/**
 * @file cargarImagenCommand.cxx
 * @brief Implementación del comando cargar_imagen
 */

#include <bits/stdc++.h>

#include <fstream>

#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/leerImagenPGM.h"

using namespace std;

/**
 * @brief Usa la funcion leerImagenPGM para cargar la imagen pasada como argv[1]
 * en el comando
 * @param argv Vector de strings que contiene los argumentos del usuario.
 *        - `argv[0]`: Nombre del programa (ignorado).
 *        - `argv[1]`: (Obligatorio) Nombre del archivo con formato pgm a ser
 * leido.
 * @param memoria Memoria del sistema
 * @return 0 si la ejecución fue exitosa
 */
int handlerCargarImagen(vector<string> argv, Memoria &memoria) {
  try {
    Imagen *imagen = leerImagenPGM(argv[1]);
    memoria.setImagenEnMemoria(imagen);

    cout << "Se ha finalizado la carga del archivo " << argv[1] << endl;

    return 0;
  } catch (const std::exception &err) {
    std::cerr << "ERROR " << argv[1] << ": " << err.what() << endl;
    return 1;
  }
}

Comando CommandManager::cargarImagenCommand = *(
    new Comando({"cargar_imagen", 2, [](vector<string> args, Memoria &memoria) {
                   return handlerCargarImagen(args, memoria);
                 }}));
