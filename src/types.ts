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
}

export interface Interface {
  readonly name: string
  readonly kind: string
  readonly parents: ReadonlyArray<string>
  readonly properties: Array<Property>
  readonly methods: Array<Method>
  readonly typeParameters: Array<string>
  readonly anonymousTypes: Array<Interface>
}

export interface Method {
  readonly name: string
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
}

export const ModuleTypeName = "t";
