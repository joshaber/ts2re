import * as TS from "typescript";
import * as Path from "path";
import {
  ModuleTypeName,
  Variable,
  Parameter,
  Method,
  Module,
  Property,
  Interface,
  NewType
} from "./types";
import { capitalized } from "./common";

const Indentation = "  ";

const Keywords = [
  "open",
  "type"
  // TODO
];

function pp(str: string, depth: number): string {
  let prefix = "";
  for (let i = 0; i < depth; i++) {
    prefix += Indentation;
  }
  return `${prefix}${str}\n`;
}

function printName(n: string): string {
  return Keywords.indexOf(n) > -1 ? `${n}_` : n;
}

function printVariable(variable: Variable): string {
  return `external ${printName(
    variable.name
  )} : ${variable.type} = "" [@@bs.val];`;
}

function printParameter(p: Parameter, includeName: boolean): string {
  if (p.stringLiteralValue) {
    return `(_ [@bs.as "${p.stringLiteralValue}"])`;
  } else if (p.phantom) {
    return `(${p.type} [@bs.ignore])`;
  } else {
    const prefix = includeName && p.name.length ? `${printName(p.name)}::` : "";

    const suffix = p.optional ? "?" : "";

    return `${prefix}${p.type}${suffix}`;
  }
}

function printMethod(
  m: Method,
  interface_: Interface | null,
  rootModule: Module | null
): string {
  if (m.ctor || m.maker) {
    const bsAttribute = m.ctor ? "new" : "obj";
    const params = m.parameters.length
      ? m.parameters.map(p => printParameter(p, m.maker)).join(" => ")
      : "unit";
    const suffix = m.ctor ? ` [@@bs.module "${rootModule!.name}"]` : "";
    const ffiName = m.ctor ? m.moduleName : "";
    return `external ${printName(
      m.name
    )} : ${params} => ${ModuleTypeName} = "${ffiName}" [@@bs.${bsAttribute}]${suffix};`;
  } else if (m.callSignature) {
    const params = m.parameters.length
      ? m.parameters.map(p => printParameter(p, m.maker)).join(" => ")
      : "unit";
    // TODO: This is pretty wrong
    if (rootModule) {
      return `external ${printName(
        m.name
      )} : ${params} => ${ModuleTypeName} = "${rootModule.name}" [@@bs.module];`;
    } else {
      return "";
    }
  } else if (!m.static) {
    let typeParams = "";
    if (interface_) {
      typeParams = printTypeParameters(interface_);
    }

    const params = m.parameters.length
      ? " => " + m.parameters.map(p => printParameter(p, false)).join(" => ")
      : "";
    const bindingName = m.name === m.bindingName ? "" : m.bindingName;
    return `external ${printName(
      m.name
    )} : ${ModuleTypeName}${typeParams}${params} => ${m.type} = "${bindingName}" [@@bs.send];`;
  } else {
    const bindingName = m.name === m.bindingName ? "" : m.bindingName;
    const params = m.parameters.length
      ? m.parameters.map(p => printParameter(p, false)).join(" => ")
      : "unit";
    const name = printName(m.name);
    return `external ${name} : ${params} => ${m.type} = "${bindingName}" [@@bs.module "${rootModule!
      .name}"];`;
  }
}

function printProperty(p: Property, depth: number): string {
  let str = "";
  str += pp(
    `external set${capitalized(p.name)} : ${ModuleTypeName} => ${p.optional
      ? "option "
      : ""}${p.type} => unit = "${p.name}" [@@bs.set];`,
    depth
  );
  str += pp(
    `external get${capitalized(p.name)} : ${ModuleTypeName} => ${p.optional
      ? "option "
      : ""}${p.type} = "${p.name}" [@@bs.get]${p.optional
      ? " [@@bs.return null_undefined_to_opt]"
      : ""};`,
    depth
  );
  str += "\n";
  return str;
}

function printNewType(t: NewType, depth: number): string {
  let str = "";

  str += pp(`type ${t.name} ${t.typeParameters.join(" ")} =`, depth);
  for (const [i, c] of t.cases.entries()) {
    const last = i === t.cases.length - 1;
    str += pp(`| ${c.name} : ${t.name} ${c.type}${last ? ";" : ""}`, depth + 1);
  }

  return str;
}

function printInterface(
  i: Interface,
  rootModule: Module | null,
  depth: number
): string {
  let str = "";
  str += pp(`let module ${capitalized(i.name)} = {`, depth);

  const typeParams = printTypeParameters(i);
  str += pp(`type ${ModuleTypeName}${typeParams};`, depth + 1);
  str += "\n";

  for (const anon of i.anonymousTypes) {
    if (anon.kind === "interface") {
      str += printInterface(anon.interface, rootModule, depth + 1);
    } else if (anon.kind === "newtype") {
      str += printNewType(anon.newType, depth + 1);
    }
    str += "\n";
  }

  for (const meth of i.methods) {
    str += pp(printMethod(meth, i, rootModule), depth + 1);
  }

  for (const prop of i.properties) {
    str += printProperty(prop, depth + 1);
  }

  str += pp("};", depth);
  return str;
}

export function printModule(
  m: Module,
  rootModule: Module | null,
  depth: number
): string {
  let str = "";
  const isRoot = !rootModule;
  if (!isRoot) {
    str += pp(`let module ${capitalized(m.name)} = {`, depth);
    str += "\n";
  }

  const childDepth = isRoot ? depth : depth + 1;

  for (const variable of m.variables) {
    str += pp(printVariable(variable), childDepth);
  }

  for (const method of m.methods) {
    str += pp(printMethod(method, null, rootModule || m), childDepth);
  }

  for (const i of m.interfaces) {
    str += printInterface(i, rootModule || m, childDepth);
    str += "\n";
  }

  for (const mx of m.modules) {
    str += printModule(mx, m, childDepth);
    str += "\n";
  }

  if (!isRoot) {
    str += pp("};", depth);
  }

  return str;
}

function printTypeParameters(i: Interface): string {
  if (i.typeParameters.length) {
    return " " + i.typeParameters.map(p => `'${p}`).join(" ");
  } else {
    return "";
  }
}
