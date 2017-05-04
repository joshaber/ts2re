import * as Path from "path";
import * as TS from "typescript";
import * as FS from "fs";

import { printModule } from './print'
import {
  Module,
  ModuleTypeName,
  Variable,
  Parameter,
  Method,
  Property,
  Interface,
} from './types'

// // TODO:
const MappedTypes = {
  Date: "DateTime",
  Object: "obj",
  Array: "ResizeArray",
  RegExp: "Regex",
  String: "string",
  Number: "float",
  'Function.t': "('x => 'y)",
};

const TestInputFile = "electron.d.ts"

const root = Path.join(__dirname, "..");

const filePath = Path.join(root, TestInputFile);
const prog = TS.createProgram([ filePath ], TS.getDefaultCompilerOptions());

const file = prog.getSourceFile(filePath);
const out = parseFile(file);

const printed = printModule(out, null, 0);
FS.writeFileSync(Path.join(root, `${out.name}.re`), printed);

function parseFile(file: TS.SourceFile): Module {
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

function getType(type): string {
  if (!type) {
    return "'a";
  }

  switch (type.kind) {
    case TS.SyntaxKind.StringKeyword:
      return "string";
    case TS.SyntaxKind.NumberKeyword:
      return "float";
    case TS.SyntaxKind.BooleanKeyword:
      return "bool";
    case TS.SyntaxKind.VoidKeyword:
      return "unit";
    case TS.SyntaxKind.SymbolKeyword:
      // TODO:
      return "Symbol";
    case TS.SyntaxKind.ArrayType:
      return `(array ${getType(type.elementType)})`
    case TS.SyntaxKind.FunctionType:
      const cbParams = type.parameters.map(function (x) {
        return x.dotDotDotToken ? "'a" : getType(x.type);
      }).join(" => ");
      return "(" + (cbParams || "unit") + " => " + getType(type.type) + ")";
    case TS.SyntaxKind.UnionType:
      // TODO:
      if (type.types && type.types[0].kind == TS.SyntaxKind.StringLiteral)
        return "(* TODO StringEnum " + type.types.map(x=>x.text).join(" | ") + " *) string";
      else if (type.types.length <= 4)
        // TODO:
        return "'a";
      else
        // TODO:
        return "'a";
    case TS.SyntaxKind.TupleType:
      return type.elementTypes.map(getType).join(" * ");
    case TS.SyntaxKind.ParenthesizedType:
      return getType(type.type);
    case TS.SyntaxKind.ThisType:
      return ModuleTypeName;
    default:
      let name = type.typeName ? `${type.typeName.text}.${ModuleTypeName}` : (type.expression ? type.expression.text : null)
      if (type.expression && type.expression.kind == TS.SyntaxKind.PropertyAccessExpression) {
        name = type.expression.expression.text + "." + type.expression.name.text;
      }
      if (type.typeName && type.typeName.left && type.typeName.right) {
        name = type.typeName.left.text + "." + `${type.typeName.right.text}.${ModuleTypeName}`;
      }

      // TODO:
      if (!name) {
        return "'a"
      }

      const t = MappedTypes[name]
      if (t) {
        name = t;
      }

      const typeParameters = findTypeParameters(type);
      const result = `${name}${printTypeArguments(type.typeArguments)}`
      return (typeParameters.indexOf(result) > -1 ? "'" : "") + result;
  }
}

function getVariables(node: any): ReadonlyArray<Variable> {
  const declarationList = Array.isArray(node.declarationList)
    ? node.declarationList
    : [ node.declarationList ];
  const variables = new Array<Variable>()
  for (const declarations of declarationList) {
    for (const declaration of declarations) {
      const name = declaration.name.text
      let type: string
      if (declaration.type.kind == TS.SyntaxKind.TypeLiteral) {
        const i = visitInterface(declarations.type, { name: name + "Type", anonymous: true });
        // TODO
        // anonymousTypes.push(type);
        type = i.name;
      } else {
        type = getType(declarations.type);
      }

      variables.push({
        name: name,
        type: type,
        static: true,
        parameters: []
      });
    }
  }

  return variables
}

function getProperty(node, opts: any = {}): Property {
  return {
    name: opts.name || getName(node),
    type: getType(node.type),
    optional: node.questionToken != null,
    static: node.name ? hasFlag(node.name.parserContextFlags, TS.ModifierFlags.Static) : false
  };
}

function visitInterface(node, opts) {
  const ifc = getInterface(node, opts);
  const members = opts.kind === 'type-alias' ? node.type.members : node.members;
  (members || []).forEach(function(node) {
    let member, name;
    switch (node.kind) {
      case TS.SyntaxKind.PropertySignature:
      case TS.SyntaxKind.PropertyDeclaration:
        if (node.name.kind == TS.SyntaxKind.ComputedPropertyName) {
          name = getName(node.name);
          member = getProperty(node, { name: "["+name+"]" });
          member.emit = "$0["+name+"]{{=$1}}";
        } else {
          member = getProperty(node);
        }
        ifc.properties.push(member);
        break;
      // TODO: If interface only contains one `Invoke` method
      // make it an alias of Func
      case TS.SyntaxKind.CallSignature:
        member = getMethod(node, { name: "invoke", moduleName: ifc.name });
        member.emit = "$0($1...)";
        ifc.methods.push(member);
        break;
      case TS.SyntaxKind.MethodSignature:
      case TS.SyntaxKind.MethodDeclaration:
        if (node.name.kind == TS.SyntaxKind.ComputedPropertyName) {
          name = getName(node.name);
          member = getMethod(node, { name: "["+name+"]", moduleName: ifc.name });
          member.emit = "$0["+name+"]($1...)";
        } else {
          member = getMethod(node, { moduleName: ifc.name });
        }

        ifc.methods.push(member);
        break;
      case TS.SyntaxKind.ConstructSignature:
        member = getMethod(node, { name: "Create", moduleName: ifc.name });
        member.emit = "new $0($1...)";
        ifc.methods.push(member);
        break;
      case TS.SyntaxKind.IndexSignature:
        member = getMethod(node, { name: "value", moduleName: ifc.name });
        // TODO:
        member.emit = "$0[$1]{{=$2}}";
        ifc.properties.push(member);
        break;
      case TS.SyntaxKind.Constructor:
        member = getMethod(node, { name: 'make', ctor: true, moduleName: ifc.name });
        ifc.methods.push(member);
        // ifc.constructorParameters = node.parameters.map(getParameter);
        break;
    }
  });

  // Classes already have constructors, but interfaces and type aliases should
  // have a convenience make function.
  if (opts.kind !== 'class') {
    const params = ifc.properties.map(p => ({
      name: p.name,
      optional: p.optional,
      type: p.type,
      rest: false,
    }))

    if ((params as any).find(p => p.optional)) {
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

  return ifc;
}

function getInterface(node, opts: any = {}): Interface {
  function printTypeParameters(typeParams) {
    typeParams = typeParams || [];
    return typeParams.length == 0 ? "" : "(" + typeParams.map(function (x) {
        return "'" + x.name.text
    }).join(", ") + ")";
  }

  const ifc: Interface = {
    name: opts.name || (getName(node) + printTypeParameters(node.typeParameters)),
    kind: opts.kind || "interface",
    parents: opts.kind == "alias" ? [getType(node.type)] : getParents(node),
    properties: [],
    methods: [],
  };
  if (!opts.anonymous)
    // TODO:
    // typeCache[joinPath(ifc.path, ifc.name.replace(genReg,""))] = ifc;
  return ifc;
}

function getParents(node): ReadonlyArray<string> {
  const parents = [];
  if (Array.isArray(node.heritageClauses)) {
    for (let i = 0; i < node.heritageClauses.length; i++) {
      const types = node.heritageClauses[i].types;
      for (let j = 0; j < types.length; j++) {
        parents.push(getType(types[j]));
      }
    }
  }
  return parents;
}

function hasFlag(flags, flag) {
  return flags != null && (flags & flag) == flag;
}

function getMethod(node, opts: any = {}): Method {
  const meth: Method = {
    name: opts.name || getName(node),
    type: getType(node.type),
    optional: node.questionToken != null,
    static: opts.static
          || (node.name && hasFlag(node.name.parserContextFlags, TS.ModifierFlags.Static))
          || (node.modifiers && hasFlag(node.modifiers.flags, TS.ModifierFlags.Static)),
    parameters: node.parameters.map(getParameter),
    ctor: opts.ctor || false,
    maker: false,
    moduleName: opts.moduleName || '',
  };

  const containsOptionalParam = !!(meth.parameters as any).find(p => p.optional)
  if (containsOptionalParam) {
    const sentinelParam: Parameter = {
      name: '',
      type: 'unit',
      optional: false,
      rest: false,
    }
    meth.parameters.push(sentinelParam)
  }

  return meth;
}

function getParameter(param): Parameter {
  return {
    name: param.name.text,
    type: getType(param.type),
    optional: param.questionToken != null,
    rest: param.dotDotDotToken != null,
  };
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
        // TODO:
        if ((node as any).type.types && (node as any).type.types[0].kind == TS.SyntaxKind.StringLiteral) {
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
        m.methods.push(getMethod(node, { static: true, moduleName: m.name }));
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
  return typeArgs.length == 0 ? "" : " (" + typeArgs.map(getType).join(", ") + ")";
}
