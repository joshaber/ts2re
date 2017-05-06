import * as Path from "path";
import * as TS from "typescript";
import * as FS from "fs";

import { printModule } from './print'
import { parseFile } from './parse'

const TestInputFile = "electron.d.ts"

const root = Path.join(__dirname, "..");

const filePath = Path.join(root, TestInputFile);
const prog = TS.createProgram([ filePath ], TS.getDefaultCompilerOptions());

const file = prog.getSourceFile(filePath);
const out = parseFile(file);

const printed = printModule(out, null, 0);
FS.writeFileSync(Path.join(root, `${out.name}.re`), printed);
