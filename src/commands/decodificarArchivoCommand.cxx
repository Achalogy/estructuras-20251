/**
 * @file decodificarArchivoCommand.cxx
 * @brief Implementación del comando encargado de decodificar un archivo que
 * debe contener una imagen en formato PGM códificada haciendo uso del algoritmo
 * de Huffman
 *
 * Este archivo contiene la implementación de la función
 * `handlerDecodificarImagen`, que genera un nuevo archivo PGM (argv[2]) con el
 * contenido decodificado de la imagen almacenada en el archiv argv[1].
 */

#include <bits/stdc++.h>

#include <fstream>

#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/guardarImagenPGM.h"
#include "../utils/leerImagenHuff.h"

using namespace std;

/**
 * @brief Decodifica y genera el archivo PGM de una imagen codificada con el
 * algoritmo de Huffman
 *
 * @param argv Vector de strings que contiene los argumentos del usuario.
 *        - `argv[0]`: Nombre del programa (ignorado).
 *        - `argv[1]`: (Obligatorio) Nombre del archivo binario codificado con
 * el algoritmo Huffman
 *        - `argv[2]`: (Obligatorio) Nombre del archivo PGM destino de la
 * información decodificada desde el archivo binario
 *
 * @param memoria Memoria del sistema
 *
 * @return 0 si la ejecución fue exitosa.
 */
int handlerDecodificarArchivo(vector<string> argv, Memoria &memoria) {
  Imagen *imagen = NULL;

  try {
    cout << "Comenzando a cargar el archivo..." << endl;
    Imagen *imagen = leerImagenHuff(argv[1]);
    memoria.setImagenEnMemoria(imagen);

    cout << "Se ha finalizado la carga y decodificacion del archivo " << argv[1]

         << endl;

    guardarImagenPGM(imagen, argv[2]);

    std::cout << "Archivo " << argv[2] << " guardado con exito" << std::endl;
    return 0;
  } catch (const std::exception &err) {
    std::cerr << "ERROR " << argv[1] << ": " << err.what() << endl;
    return 1;
  }
}

Comando CommandManager::decodificarArchivoCommand = *(new Comando(
    {"decodificar_archivo", 3, [](vector<string> args, Memoria &memoria) {
       return handlerDecodificarArchivo(args, memoria);
     }}));