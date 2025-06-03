/*
  Crea un entregable para Campus siguiendo la estructura pedida.
*/

import { copyFile, copyFileSync, existsSync, mkdirSync, readdirSync, readFileSync, rmSync, statSync, writeFileSync } from "fs";
import path from "path";

const rawDirsandFiles = readdirSync(".", { recursive: true }).map(x => x.toString())
const ignoreRegex = readFileSync(".campusignore", "utf-8")
  .split("\n")
  .map(x => x.trim())
  .filter(x => x && !x.startsWith("#"))
  .map(pattern => {
    const regexPattern = pattern
      .replace(/\//g, "(\\\\+)?")   // Escapar puntos
      .replace(/\./g, "\\.")   // Escapar puntos
      .replace(/\*/g, ".*");   // Convertir '*' en '.*'  
    return new RegExp(`^${regexPattern}$`);
  })

const files = rawDirsandFiles
  .filter(x => !ignoreRegex.some(r => r.exec(x)))
  .filter(x => statSync(x).isFile())


console.log("Creando .build")

try {
  mkdirSync('.build')
} catch (err: any) {
  if (err.code == "EEXIST") {
    console.log("\nYa existe la carpeta .build")
    console.log("  Borrando y creando una nueva...")

    rmSync('.build', { recursive: true, force: true })
    mkdirSync('.build')
  }
}

console.log("\nCopiando archivos\n")

let newFiles = []

for (let file of files) {
  try {
    const dest = path.join(".build", file.split("\\").at(-1) ?? "");

    console.log(" - Copiando", file, "a", dest)
    copyFileSync(file, dest)

    newFiles.push(dest)
  } catch (err) {
    console.log("  Hubo un error al copiar", file)
  }
}

console.log("Normalizando #includes")

for (let file of newFiles) {
  if (
    ![".cpp", ".cxx", ".h", ".hxx"].includes(path.extname(file))
  ) continue;

  console.log(" - Normalizando", file)

  const content = readFileSync(file, "utf-8")
  const nContent = content.replace(/#include "(.*)"/g, (_, file) => `#include "${file.split("/")?.at(-1)}"`)

  writeFileSync(file, nContent)
}

console.log("\nEntrega creada en .build/\n")