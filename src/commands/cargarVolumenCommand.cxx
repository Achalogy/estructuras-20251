/**
 * @file cargarVolumenCommand.cxx
 * @brief Implementación del comando cargar_volumen
 */

#include <bits/stdc++.h>

#include <fstream>

#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/leerVolumen.h"

#define endl "\n"

using namespace std;

/**
 * @brief Usa la funcion leerVolumen para cargar la serie de imagenes con el
 * baseName especificado por el usuario
 * @param argv Vector de strings que contiene los argumentos del usuario.
 *        - `argv[0]`: Nombre del programa (ignorado).
 *        - `argv[1]`: (Obligatorio) baseName de los archivos a cargar como
 * volumen.
 *        - `argv[2]`: (Obligatorio) cantidad de imagenes que conformar el
 * volumen a ser leido.
 * @param memoria Memoria del sistema
 * @return 0 si la ejecución fue exitosa
 */
int handlerCargarVolumen(vector<string> argv, Memoria &memoria) {
  char *endptr;
  long n_im = std::strtol(argv[2].c_str(), &endptr, 10);

  try {
    if (*endptr != '\0')
      throw std::runtime_error("Formato invalido para la cantidad de imagenes");

    Volumen *volumen = leerVolumen(argv[1], (int)n_im);

    memoria.setVolumenEnMemoria(volumen);

    cout << "Se ha finalizado la cargar del volumen " << argv[1] << endl;

    return 0;
  } catch (const std::exception &err) {
    std::cerr << "ERROR cargando volumen " << argv[1] << ": " << err.what()
              << endl;
    return 1;
  }
}

Comando CommandManager::cargarVolumenCommand = *(new Comando(
    {"cargar_volumen", 3, [](vector<string> args, Memoria &memoria) {
       return handlerCargarVolumen(args, memoria);
     }}));