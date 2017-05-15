export interface Variable {
  readonly name: string
  readonly type: string
  readonly static: boolean
  readonly parameters: Array<Parameter>
}

export interface Property {
  readonly name: string
  readonly type: string
  readonly optional: boolean
  readonly static: boolean
}

export interface Parameter {
  readonly name: string
  readonly type: string
  readonly optional: boolean
  readonly rest: boolean
  readonly stringLiteralValue?: string
  readonly phantom: boolean
}

export interface Interface {
  readonly name: string
  readonly kind: string
  readonly parents: ReadonlyArray<string>
  readonly properties: Array<Property>
  readonly methods: Array<Method>
  readonly typeParameters: Array<string>
  readonly anonymousTypes: Array<AnonymousType>
}

export interface Method {
  readonly name: string
  // This will be different from `name` if the method was deduplicated.
  readonly bindingName: string
  readonly type: string
  readonly optional: boolean
  readonly static: boolean
  readonly parameters: Array<Parameter>

  /** Constructor for a class. */
  readonly ctor: boolean

  readonly moduleName: string

  /** Maker for an interface/object. */
  readonly maker: boolean
}

export interface Module {
  readonly name: string
  readonly modules: Array<Module>
  readonly variables: Array<Variable>
  readonly interfaces: Array<Interface>
  readonly methods: Array<Method>
  readonly anonymousTypes: Array<AnonymousType>
}

export interface NewType {
  readonly name: string
  readonly typeParameters: ReadonlyArray<string>
  readonly cases: ReadonlyArray<Case>
}

export interface Case {
  readonly name: string
  readonly type: string
}

export type AnonymousType =
  | { kind: 'interface', interface: Interface }
  | { kind: 'newtype', newType: NewType }

export const ModuleTypeName = "t";
