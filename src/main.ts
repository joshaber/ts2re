import * as Path from "path";
import * as TS from "typescript";
import * as FS from "fs";

interface Variable {
  readonly name: string
  readonly type: string
  readonly static: boolean
  readonly parameters: Array<Parameter>
}

interface Property {
  readonly name: string
  readonly type: string
  readonly optional: boolean
  readonly static: boolean
}

interface Parameter {
  readonly name: string
  readonly type: string
  readonly optional: boolean
  readonly rest: boolean
}

interface Interface {
  readonly name: string
  readonly kind: string
  readonly parents: ReadonlyArray<string>
  readonly properties: Array<Property>
  readonly methods: Array<Method>
  constructorParameters: Array<Parameter>
}

interface Method {
  readonly name: string
  readonly type: string
  readonly optional: boolean
  readonly static: boolean
  readonly parameters: Array<Parameter>
  readonly emit: string | null,
}

interface TypeAlias {
  readonly name: string
  readonly parents: ReadonlyArray<string>
  readonly properties: Array<Property>
}

interface Module {
  readonly name: string
  readonly modules: Array<Module>
  readonly variables: Array<Variable>
  readonly interfaces: Array<Interface>
  readonly methods: Array<Method>
  readonly typeAliases: Array<TypeAlias>
}

// // TODO:
const MappedTypes = {
  Date: "DateTime",
  Object: "obj",
  Array: "ResizeArray",
  RegExp: "Regex",
  String: "string",
  Number: "float",
  'Function.t': "(<..> => <..>)",
};

const ModuleTypeName = "t";

const filePath = Path.join(__dirname, "..", "electron.d.ts");
const prog = TS.createProgram([ filePath ], TS.getDefaultCompilerOptions());

const file = prog.getSourceFile(filePath);
const out = parseFile(file);

const printed = printModule(out, true, 0);
FS.writeFileSync(Path.join(__dirname, '..', 'electron.rei'), printed);

function pp(str: string, depth: number): string {
  let prefix = ''
  for (let i = 0; i < depth; i++) {
    prefix += '  '
  }
  return `${prefix}${str}\n`
}

function printVariable(variable: Variable): string {
  return `external ${variable.name} : ${variable.type} = "" [@@bs.val];`
}

function printParameter(p: Parameter): string {
  return p.optional ? `?${p.name}::${p.type}` : `${p.type}`
}

function printMethod(m: Method): string {
  const params = m.parameters.length
    ? " => " + m.parameters.map(printParameter).join(" => ")
    : ""
  return `external ${m.name} : ${ModuleTypeName}${params} => ${m.type} = "" [@@bs.send];`
}

function printProperty(p: Property, depth: number): string {
  let str = ''
  str += pp(`external set${capitalize(p.name)} : ${ModuleTypeName} => ${p.optional ? 'option ' : ''}${p.type} => unit = "${p.name}" [@@bs.set];`, depth)
  str += pp(`external get${capitalize(p.name)} : ${ModuleTypeName} => ${p.optional ? 'option ' : ''}${p.type} = "${p.name}" [@@bs.get]${p.optional ? ' [@@bs.return null_undefined_to_opt]' : ''};`, depth)
  str += '\n'
  return str
}

function printMaker(i: Interface, depth: number): string {
  let str = ''
  if (i.properties.length) {
    const p = i.properties.map(p => `${p.name}::${p.type}`).join(" => ") + " =>"
    str += pp(`external make : ${p} unit => ${ModuleTypeName} = "" [@@bs.obj]`, depth)
    str += '\n'
  }

  return str
}

function printInterface(i: Interface, depth: number): string {
  let str = ''
  str += pp(`module ${i.name} = {`, depth)
  str += pp(`type ${ModuleTypeName};`, depth + 1)
  str += '\n'

  str += printMaker(i, depth + 1)

  for (const meth of i.methods) {
    str += pp(printMethod(meth), depth + 1)
  }

  for (const prop of i.properties) {
    str += printProperty(prop, depth + 1)
  }

  str += pp('};', depth)
  return str
}

function printTypeAlias(alias: TypeAlias, depth: number): string {
  let str = ''
  str += pp(`type ${uncapitalize(alias.name)} = {`, depth)
  str += alias.properties.map(p => pp(`${p.name}: ${p.type},`, depth + 1)).join('')
  str += pp('};', depth)
  return str
}

function printModule(m: Module, skipSelf: boolean, depth: number): string {
  let str = ''
  str += pp(`module ${m.name} = {`, depth)
  str += '\n'

  for (const alias of m.typeAliases) {
    str += printTypeAlias(alias, depth + 1)
    str += '\n'
  }

  for (const variable of m.variables) {
    str += pp(printVariable(variable), depth + 1)
  }

  for (const method of m.methods) {
    str += printMethod(method)
  }

  for (const i of m.interfaces) {
    str += printInterface(i, depth + 1)
    str += '\n'
  }

  for (const mx of m.modules) {
    str += printModule(mx, false, depth + 1)
    str += '\n'
  }

  str += pp('};', depth)

  return str
}

function printTypeArguments(typeArgs) {
  typeArgs = typeArgs || [];
  return typeArgs.length == 0 ? "" : "<" + typeArgs.map(getType).join(", ") + ">";
}

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
      return `array ${getType(type.elementType)}`
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
        return "U" + type.types.length + printTypeArguments(type.types);
      else
        // TODO:
        return "obj";
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
      const result = name + printTypeArguments(type.typeArguments);
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

function capitalize(str: string): string {
  return str.charAt(0).toUpperCase() + str.slice(1);
}

function uncapitalize(str: string): string {
  return str.charAt(0).toLowerCase() + str.slice(1);
}

function visitInterface(node, opts) {
  const ifc = getInterface(node, opts);
  (node.members || []).forEach(function(node) {
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
        member = getMethod(node, { name: "invoke" });
        member.emit = "$0($1...)";
        ifc.methods.push(member);
        break;
      case TS.SyntaxKind.MethodSignature:
      case TS.SyntaxKind.MethodDeclaration:
        if (node.name.kind == TS.SyntaxKind.ComputedPropertyName) {
          name = getName(node.name);
          member = getMethod(node, { name: "["+name+"]" });
          member.emit = "$0["+name+"]($1...)";
        } else {
          member = getMethod(node);
        }

        ifc.methods.push(member);
        break;
      case TS.SyntaxKind.ConstructSignature:
        member = getMethod(node, { name: "Create" });
        member.emit = "new $0($1...)";
        ifc.methods.push(member);
        break;
      case TS.SyntaxKind.IndexSignature:
        member = getMethod(node, { name: "Item" });
        member.emit = "$0[$1]{{=$2}}";
        ifc.properties.push(member);
        break;
      case TS.SyntaxKind.Constructor:
        ifc.constructorParameters = node.parameters.map(getParameter);
        break;
    }
  });
  return ifc;
}

function getInterface(node, opts: any = {}): Interface {
  function printTypeParameters(typeParams) {
    typeParams = typeParams || [];
    return typeParams.length == 0 ? "" : "<" + typeParams.map(function (x) {
        return "'" + x.name.text
    }).join(", ") + ">";
  }
  const ifc = {
    name: opts.name || (getName(node) + printTypeParameters(node.typeParameters)),
    kind: opts.kind || "interface",
    parents: opts.kind == "alias" ? [getType(node.type)] : getParents(node),
    properties: [],
    methods: [],
    constructorParameters: [],
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
  const meth = {
    name: opts.name || getName(node),
    type: getType(node.type),
    optional: node.questionToken != null,
    static: opts.static
          || (node.name && hasFlag(node.name.parserContextFlags, TS.ModifierFlags.Static))
          || (node.modifiers && hasFlag(node.modifiers.flags, TS.ModifierFlags.Static)),
    parameters: node.parameters.map(getParameter),
    emit: null,
  };
  const firstParam = node.parameters[0], secondParam = node.parameters[1];
  if (secondParam && secondParam.type && secondParam.type.kind == TS.SyntaxKind.StringLiteral) {
    // The only case I've seen following this pattern is
    // createElementNS(namespaceURI: "http://www.w3.org/2000/svg", qualifiedName: "a"): SVGAElement
    meth.parameters = meth.parameters.slice(2);
    meth.emit = `$0.${meth.name}('${firstParam.type.text}', ${secondParam.type.text}'${meth.parameters.length?',$1...':''})`;
    meth.name += '_' + secondParam.type.text;
  }
  else if (firstParam && firstParam.type && firstParam.type.kind == TS.SyntaxKind.StringLiteral) {
    meth.parameters = meth.parameters.slice(1);
    meth.emit = `$0.${meth.name}('${firstParam.type.text}'${meth.parameters.length?',$1...':''})`;
    meth.name += '_' + firstParam.type.text;
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

function getTypeAlias(node: any): TypeAlias {
  const alias = {
    name: getName(node),
    parents: [getType(node.type)],
    properties: [],
  };
  return alias;
}

function visitTypeAlias(node): TypeAlias {
  const alias = getTypeAlias(node);
  (node.type.members || []).forEach(function(node) {
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
        alias.properties.push(member);
        break;
      case TS.SyntaxKind.IndexSignature:
        member = getMethod(node, { name: "Item" });
        member.emit = "$0[$1]{{=$2}}";
        alias.properties.push(member);
        break;
    }
  });

  // TODO: vibrancyType

  return alias;
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
          m.typeAliases.push(visitTypeAlias(node));
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
        m.methods.push(getMethod(node, { static: true }));
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
  const typeAliases = []

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
        typeAliases: [],
      }
      body.statements.forEach(visitNode(m));
      modules.push(...m.modules)
      interfaces.push(...m.interfaces)
      variables.push(...m.variables)
      methods.push(...m.methods)
      typeAliases.push(...m.typeAliases)
      break;
  }

  return {
    name,
    modules,
    variables,
    interfaces,
    methods,
    typeAliases,
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
