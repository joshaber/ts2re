import * as Path from "path";
import * as TS from "typescript";
import * as FS from "fs";

import { printModule } from './print'
import { parseFile } from './parse'

const args = process.argv.slice(1)
const inputFile = args[args.length - 1]

const root = Path.join(__dirname, "..");

const filePath = Path.join(root, inputFile);
const prog = TS.createProgram([ filePath ], TS.getDefaultCompilerOptions());

const file = prog.getSourceFile(filePath);
const out = parseFile(file);

const printed = printModule(out, null, 0);
FS.writeFileSync(Path.join(root, `${out.name}.re`), printed);
