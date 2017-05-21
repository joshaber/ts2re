export function capitalized(str: string): string {
  return str.charAt(0).toUpperCase() + str.slice(1);
}

export function decapitalized(str: string): string {
  return str.charAt(0).toLowerCase() + str.slice(1);
}
