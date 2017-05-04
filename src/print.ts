import * as TS from "typescript";
import * as Path from 'path';
import {
  Indentation,
  Keywords,
  ModuleTypeName,
  Variable,
  Parameter,
  Method,
  Module,
  Property,
  Interface,
} from './global'

function pp(str: string, depth: number): string {
  let prefix = ''
  for (let i = 0; i < depth; i++) {
    prefix += Indentation
  }
  return `${prefix}${str}\n`
}

function printName(n: string): string {
  return Keywords.indexOf(n) > -1
    ? `${n}_`
    : n
}

function printVariable(variable: Variable): string {
  return `external ${printName(variable.name)} : ${variable.type} = "" [@@bs.val];`
}

function printParameter(p: Parameter, includeName: boolean): string {
  const prefix = (p.optional || includeName) && p.name.length
    ? `${printName(p.name)}::`
    : ''

  const suffix = p.optional
    ? '?'
    : ''

  return `${prefix}${p.type}${suffix}`
}

function printMethod(m: Method, rootModule: Module): string {
  if (m.ctor || m.maker) {
    const bsAttribute = m.ctor ? 'new' : 'obj'
    const params = m.parameters.length
      ? m.parameters.map(p => printParameter(p, true)).join(" => ")
      : "unit"
    const suffix = m.ctor
      ? ` [@@bs.module "${rootModule.name}"]`
      : ''
    const ffiName = m.ctor
      ? m.moduleName
      : ''
    return `external ${printName(m.name)} : ${params} => ${ModuleTypeName} = "${ffiName}" [@@bs.${bsAttribute}]${suffix};`
  } else if (!m.static) {
    const params = m.parameters.length
      ? " => " + m.parameters.map(p => printParameter(p, false)).join(" => ")
      : ""
    return `external ${printName(m.name)} : ${ModuleTypeName}${params} => ${m.type} = "" [@@bs.send];`
  } else {
    const params = m.parameters.length
      ? " => " + m.parameters.map(p => printParameter(p, false)).join(" => ")
      : "unit"
    return `external ${printName(m.name)} : ${params} => ${m.type} = "";`
  }
}

function printProperty(p: Property, depth: number): string {
  let str = ''
  str += pp(`external set${capitalize(p.name)} : ${ModuleTypeName} => ${p.optional ? 'option ' : ''}${p.type} => unit = "${p.name}" [@@bs.set];`, depth)
  str += pp(`external get${capitalize(p.name)} : ${ModuleTypeName} => ${p.optional ? 'option ' : ''}${p.type} = "${p.name}" [@@bs.get]${p.optional ? ' [@@bs.return null_undefined_to_opt]' : ''};`, depth)
  str += '\n'
  return str
}

function printInterface(i: Interface, rootModule: Module, depth: number): string {
  let str = ''
  str += pp(`let module ${i.name} = {`, depth)
  str += pp(`type ${ModuleTypeName};`, depth + 1)
  str += '\n'

  for (const meth of i.methods) {
    str += pp(printMethod(meth, rootModule), depth + 1)
  }

  for (const prop of i.properties) {
    str += printProperty(prop, depth + 1)
  }

  str += pp('};', depth)
  return str
}

export function printModule(m: Module, rootModule: Module | null, depth: number): string {
  let str = ''
  const isRoot = !rootModule
  if (!isRoot) {
    str += pp(`let module ${m.name} = {`, depth)
    str += '\n'
  }

  const childDepth = isRoot ? depth : depth + 1

  for (const variable of m.variables) {
    str += pp(printVariable(variable), childDepth)
  }

  for (const method of m.methods) {
    str += pp(printMethod(method, rootModule), childDepth)
  }

  for (const i of m.interfaces) {
    str += printInterface(i, rootModule, childDepth)
    str += '\n'
  }

  for (const mx of m.modules) {
    str += printModule(mx, m, childDepth)
    str += '\n'
  }

  if (!isRoot) {
    str += pp('};', depth)
  }

  return str
}

function capitalize(str: string): string {
  return str.charAt(0).toUpperCase() + str.slice(1);
}
