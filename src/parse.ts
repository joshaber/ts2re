import * as TS from "typescript";
import * as Path from "path";

import {
  Module,
  ModuleTypeName,
  Variable,
  Parameter,
  Method,
  Property,
  Interface,
} from './types'
import { capitalized } from './common'

const camelCase: (str: string) => string = require('camelcase')

// TODO:
const MappedTypes = {
  Date: "DateTime",
  Object: "obj",
  Array: "ResizeArray",
  RegExp: "Regex",
  String: "string",
  Number: "float",
  'Function.t': "('x => 'y)",
};

interface MethodParseOptions {
  readonly name?: string
  readonly ctor?: boolean
  readonly moduleName?: string
  readonly static?: boolean
}

interface InterfaceParseOptions {
  readonly name?: string
  readonly kind?: string
  readonly anonymous?: boolean
}

interface PropertyParseOptions {
  readonly name?: string
}

interface TypeParseOptions {
  readonly declarationName?: string
}

interface Type {
  readonly name: string
  readonly stringLiteralValue?: string
  readonly anonymousType?: Interface
}

export function parseFile(file: TS.SourceFile): Module {
  const rootModule = {
    name: Path.basename(file.fileName, '.d.ts'),
    modules: [],
    variables: [],
    interfaces: [],
    methods: [],
    typeAliases: [],
  }

  TS.forEachChild(file, visitNode(rootModule))

  return rootModule
}

function findTypeParameters(node, acc = []) {
  if (!node) {
    return acc;
  }
  if (Array.isArray(node.typeParameters)) {
    node.typeParameters.forEach(x => acc.push(x.name.text));
  }
  return findTypeParameters(node.parent, acc);
}

function getType(type: any, opts: TypeParseOptions = {}): Type {
  if (!type) {
    return { name: "'a" }
  }

  switch (type.kind) {
    case TS.SyntaxKind.StringKeyword:
      return { name: "string" }
    case TS.SyntaxKind.NumberKeyword:
      return { name: "float" }
    case TS.SyntaxKind.BooleanKeyword:
      return { name: "bool" }
    case TS.SyntaxKind.VoidKeyword:
      return { name: "unit" }
    case TS.SyntaxKind.SymbolKeyword:
      // TODO:
      return { name: "Symbol" }
    case TS.SyntaxKind.ArrayType: {
      const innerType = getType(type.elementType, opts)
      // TODO: This paren wrapping is a hack that needs to be generalized.
      return { name: `(array ${innerType.name})`, anonymousType: innerType.anonymousType }
    }
    case TS.SyntaxKind.FunctionType:
      const cbParams = type.parameters.map(function (x) {
        return x.dotDotDotToken ? "'a" : getType(x.type, opts).name;
      }).join(" => ");
      return { name: "(" + (cbParams || "unit") + " => " + getType(type.type, opts).name + ")" }
    case TS.SyntaxKind.UnionType:
      // TODO
      return { name: "'TypeUnion" }
    case TS.SyntaxKind.TupleType:
      return { name: type.elementTypes.map(t => getType(t, opts)).map(t => t.name).join(" * ") }
    case TS.SyntaxKind.ParenthesizedType:
      return getType(type.type, opts)
    case TS.SyntaxKind.ThisType:
      return { name: ModuleTypeName }
    case TS.SyntaxKind.TypeLiteral: {
      const i = visitInterface(type, { name: `${capitalized(opts.declarationName)}Type`, anonymous: true });
      return { name: `${i.name}.${ModuleTypeName}`, anonymousType: i }
    }
    case TS.SyntaxKind.TypeReference: {
      let name = type.typeName ? `${type.typeName.text}.${ModuleTypeName}` : (type.expression ? type.expression.text : null)
      if (type.expression && type.expression.kind == TS.SyntaxKind.PropertyAccessExpression) {
        name = type.expression.expression.text + "." + type.expression.name.text;
      }
      if (type.typeName && type.typeName.left && type.typeName.right) {
        name = type.typeName.left.text + "." + `${type.typeName.right.text}.${ModuleTypeName}`;
      }

      // TODO:
      if (!name) {
        return { name: "'Unknown" }
      }

      const t = MappedTypes[name]
      if (t) {
        name = t;
      }

      const typeParameters = findTypeParameters(type);
      const result = `${name}${printTypeArguments(type.typeArguments)}`
      return { name: (typeParameters.indexOf(result) > -1 ? "'" : "") + result }
    }
    case TS.SyntaxKind.AnyKeyword: {
      return { name: "'Any" }
    }
    case TS.SyntaxKind.IntersectionType: {
      // TODO
      return { name: "'TypeIntersection" }
    }
    case TS.SyntaxKind.ExpressionWithTypeArguments: {
      // TODO
      return { name: "'ExpressionWithTypeArguments" }
    }
    case TS.SyntaxKind.LiteralType: {
      switch (type.literal.kind) {
        case TS.SyntaxKind.StringLiteral:
          return { name: 'string', stringLiteralValue: type.literal.text }
        case TS.SyntaxKind.NumericLiteral:
          return { name: 'float' }
      }
    }
    case TS.SyntaxKind.TypeQuery: {
      // TODO
      return { name: "'TypeQuery" }
    }
    default: {
      console.log(`Unknown type! We'll emit it as "'UnknownType". Kind: ${type.kind}`)
      return { name: "'UnknownType" }
    }
  }
}

function getVariables(node: any): ReadonlyArray<Variable> {
  const declarationList = Array.isArray(node.declarationList)
    ? node.declarationList
    : [ node.declarationList ];
  const variables = new Array<Variable>()
  for (const declarations of declarationList) {
    for (let i = 0; i < declarations.length; i++) {
      const declaration = declarations[i]
      const name = declaration.name.text
      let type: string
      if (declaration.type.kind == TS.SyntaxKind.TypeLiteral) {
        const i = visitInterface(declarations.type, { name: name + "Type", anonymous: true });
        // TODO
        // anonymousTypes.push(type);
        type = i.name;
      } else {
        type = getType(declarations.type).name
      }

      variables.push({
        name,
        type,
        static: true,
        parameters: []
      });
    }
  }

  return variables
}

function getProperty(node, opts: PropertyParseOptions = {}): { property: Property, anonymousType?: Interface } {
  const name = opts.name || getName(node)
  const type = getType(node.type, { declarationName: name })
  const prop: Property = {
    name,
    type: type.name,
    optional: node.questionToken != null,
    static: node.name ? hasFlag(node.name.parserContextFlags, TS.ModifierFlags.Static) : false
  };

  return { property: prop, anonymousType: type.anonymousType }
}

function visitInterface(node, opts) {
  let ifc = getInterface(node, opts);
  const members = opts.kind === 'type-alias' ? node.type.members : node.members;
  (members || []).forEach(function(node) {
    switch (node.kind) {
      case TS.SyntaxKind.PropertySignature:
      case TS.SyntaxKind.PropertyDeclaration: {
        if (node.name.kind == TS.SyntaxKind.ComputedPropertyName) {
          const name = getName(node.name);
          const member = getProperty(node, { name: "["+name+"]" })
          ifc.properties.push(member.property)
          if (member.anonymousType) {
            ifc.anonymousTypes.push(member.anonymousType)
          }

          // TODO
          // member.emit = "$0["+name+"]{{=$1}}";
        } else {
          const member = getProperty(node)
          ifc.properties.push(member.property)
          if (member.anonymousType) {
            ifc.anonymousTypes.push(member.anonymousType)
          }
        }
      } break;
      // TODO: If interface only contains one `Invoke` method
      // make it an alias of Func
      case TS.SyntaxKind.CallSignature: {
        const member = getMethod(node, { name: "invoke", moduleName: ifc.name })
        // member.emit = "$0($1...)";
        ifc.methods.push(member.method)
        ifc.anonymousTypes.push(...member.anonymousTypes)
      } break;
      case TS.SyntaxKind.MethodSignature:
      case TS.SyntaxKind.MethodDeclaration: {
        if (node.name.kind == TS.SyntaxKind.ComputedPropertyName) {
          const name = getName(node.name);
          const member = getMethod(node, { name: "["+name+"]", moduleName: ifc.name })
          ifc.methods.push(member.method)
          ifc.anonymousTypes.push(...member.anonymousTypes)
          // member.emit = "$0["+name+"]($1...)";
        } else {
          const member = getMethod(node, { moduleName: ifc.name })
          ifc.methods.push(member.method)
          ifc.anonymousTypes.push(...member.anonymousTypes)
        }
      } break;
      case TS.SyntaxKind.ConstructSignature: {
        const member = getMethod(node, { name: "Create", moduleName: ifc.name });
        // member.emit = "new $0($1...)";
        ifc.methods.push(member.method)
        ifc.anonymousTypes.push(...member.anonymousTypes)
      } break;
      case TS.SyntaxKind.IndexSignature: {
        const member = getMethod(node, { name: "value", moduleName: ifc.name });
        // TODO:
        // member.emit = "$0[$1]{{=$2}}";
        ifc.methods.push(member.method)
        ifc.anonymousTypes.push(...member.anonymousTypes)
      } break;
      case TS.SyntaxKind.Constructor: {
        const member = getMethod(node, { name: 'make', ctor: true, moduleName: ifc.name });
        ifc.methods.push(member.method)
        ifc.anonymousTypes.push(...member.anonymousTypes)
        // ifc.constructorParameters = node.parameters.map(getParameter);
      } break;
    }
  });

  // Classes already have constructors, but interfaces and type aliases should
  // have a convenience make function.
  if (opts.kind !== 'class') {
    const params: Array<Parameter> = ifc.properties.map(p => ({
      name: p.name,
      optional: p.optional,
      type: p.type,
      rest: false,
    }))

    if (params.find(p => p.optional)) {
      const sentinelParam: Parameter = {
        name: '',
        type: 'unit',
        optional: false,
        rest: false,
      }
      params.push(sentinelParam)
    }

    const makeMeth: Method = {
      name: 'make',
      bindingName: 'make',
      type: ModuleTypeName,
      optional: false,
      static: true,
      parameters: params,
      ctor: false,
      maker: true,
      moduleName: ifc.name,
    }

    ifc.methods.push(makeMeth);
  }

  // We could have duplicate methods that vary by their types. For now,
  // we'll just uniquify them by index.
  // TODO: Unique using something smarter
  const updatedMethods = deduplicateMethods(ifc.methods)

  ifc = { ...ifc, methods: updatedMethods }

  return ifc;
}

function deduplicateMethods(methods: ReadonlyArray<Method>): Array<Method> {
  const dedupedByStringLiterals = methods.map(method => {
    // TODO: This is super inefficient
    const existingMethods = methods.filter(m => m.name === method.name)
    if (existingMethods.length > 1) {
      if (method.parameters.length && method.parameters[0].stringLiteralValue) {
        const literal = method.parameters[0].stringLiteralValue
        const sanitized = capitalized(camelCase(literal))
        const newName = `${method.name}${sanitized}`
        return { ...method, name: newName }
      } else {
        return method
      }
    } else {
      return method
    }
  })

  return dedupedByStringLiterals.map(method => {
    // TODO: This is super inefficient
    const existingMethods = dedupedByStringLiterals.filter(m => m.name === method.name)
    if (existingMethods.length > 1) {
      const i = existingMethods.findIndex(m => m === method)
      const uniqueSuffix = i.toString()
      const newName = `${method.name}${uniqueSuffix}`
      return { ...method, name: newName }
    } else {
      return method
    }
  })
}

function getInterface(node, opts: InterfaceParseOptions = {}): Interface {
  const ifc: Interface = {
    name: opts.name || getName(node),
    kind: opts.kind || "interface",
    parents: opts.kind == "alias" ? [ getType(node.type).name ] : getParents(node),
    properties: [],
    methods: [],
    typeParameters: (node.typeParameters || []).map(x => x.name.text),
    anonymousTypes: [],
  };
  // TODO:
  // if (!opts.anonymous)
    // typeCache[joinPath(ifc.path, ifc.name.replace(genReg,""))] = ifc;

  return ifc;
}

function getParents(node): ReadonlyArray<string> {
  const parents: Array<string> = [];
  if (Array.isArray(node.heritageClauses)) {
    for (let i = 0; i < node.heritageClauses.length; i++) {
      const types = node.heritageClauses[i].types;
      for (let j = 0; j < types.length; j++) {
        parents.push(getType(types[j]).name);
      }
    }
  }
  return parents;
}

function hasFlag(flags, flag) {
  return flags != null && (flags & flag) == flag;
}

function getMethod(node, opts: MethodParseOptions = {}): { method: Method, anonymousTypes: ReadonlyArray<Interface> } {
  const params = node.parameters.map(n => getParameter(n))
  const name = opts.name || getName(node)
  const type = getType(node.type, { declarationName: name })
  const meth: Method = {
    name,
    bindingName: name,
    type: type.name,
    optional: node.questionToken != null,
    static: opts.static
          || (node.name && hasFlag(node.name.parserContextFlags, TS.ModifierFlags.Static))
          || (node.modifiers && hasFlag(node.modifiers.flags, TS.ModifierFlags.Static)),
    parameters: params.map(p => p.parameter),
    ctor: opts.ctor || false,
    maker: false,
    moduleName: opts.moduleName || '',
  };

  const containsOptionalParam = !!meth.parameters.find(p => p.optional)
  if (containsOptionalParam) {
    const sentinelParam: Parameter = {
      name: '',
      type: 'unit',
      optional: false,
      rest: false,
    }
    meth.parameters.push(sentinelParam)
  }

  const anonTypes = params.filter(p => p.anonymousType).map(p => p.anonymousType)
  if (type.anonymousType) {
    anonTypes.push(type.anonymousType)
  }
  return { method: meth, anonymousTypes: anonTypes }
}

function getParameter(node): { parameter: Parameter, anonymousType?: Interface } {
  const name = node.name.text
  const type = getType(node.type, { declarationName: name })
  const param: Parameter = {
    name,
    type: type.name,
    optional: node.questionToken != null,
    rest: node.dotDotDotToken != null,
    stringLiteralValue: type.stringLiteralValue,
  }

  return {
    parameter: param,
    anonymousType: type.anonymousType,
  }
}

function visitNode(m: Module) {
  return function(node: TS.Node) {
    switch (node.kind) {
      case TS.SyntaxKind.InterfaceDeclaration:
        m.interfaces.push(visitInterface(node, { kind: "interface" }));
        break;

      case TS.SyntaxKind.ClassDeclaration:
        m.interfaces.push(visitInterface(node, { kind: "class" }));
        break;

      case TS.SyntaxKind.TypeAliasDeclaration:
        if ((node as any).type.types && (node as any).type.types[0].kind == TS.SyntaxKind.StringLiteral) {
          // TODO:
          // m.interfaces.push(getStringEnum(node))
        } else {
          m.interfaces.push(visitInterface(node, { kind: 'type-alias' }));
        }
        break;

      case TS.SyntaxKind.VariableStatement:
        const variables = getVariables(node);
        m.variables.push(...variables)
        // TODO:
        // varsAndTypes.variables.forEach(x => mod.properties.push(x));
        // varsAndTypes.anonymousTypes.forEach(x => mod.interfaces.push(x));
        break;

      case TS.SyntaxKind.FunctionDeclaration:
        const member = getMethod(node, { static: true, moduleName: m.name })
        m.methods.push(member.method)
        m.interfaces.push(...member.anonymousTypes)
        break;

      case TS.SyntaxKind.ModuleDeclaration:
        const visitedModule = visitModule(node)
        m.modules.push(visitedModule)
        break;

      case TS.SyntaxKind.EnumDeclaration:
        // TODO:
        // mod.interfaces.push(getEnum(node));
        break;
    }
  };
}

function visitModule(node: TS.Node): Module {
  const name = getName(node)
  const modules = []
  const interfaces = []
  const variables = []
  const methods = []

  const body = (node as any).body
  switch (body.kind) {
    case TS.SyntaxKind.ModuleDeclaration:
      modules.push(visitModule(body));
      break;

    case TS.SyntaxKind.ModuleBlock:
      const m: Module = {
        name,
        modules: [],
        variables: [],
        interfaces: [],
        methods: [],
      }
      body.statements.forEach(visitNode(m));
      modules.push(...m.modules)
      interfaces.push(...m.interfaces)
      variables.push(...m.variables)
      methods.push(...m.methods)
      break;
  }

  return {
    name,
    modules,
    variables,
    interfaces,
    methods,
  }
}

function getName(node: TS.Node) {
  const expression: TS.Expression = (node as any).expression
  if (expression && expression.kind == TS.SyntaxKind.PropertyAccessExpression) {
    return (expression as any).expression.text + "." + (expression as any).name.text;
  } else {
    // TODO: Throw exception if there's no name?
    return (node as any).name ? (node as any).name.text : (expression ? (expression as any).text : null);
  }
}

function printTypeArguments(typeArgs) {
  typeArgs = typeArgs || [];
  return typeArgs.length == 0 ? "" : " (" + typeArgs.map(getType).map(t => t.name).join(", ") + ")";
}
