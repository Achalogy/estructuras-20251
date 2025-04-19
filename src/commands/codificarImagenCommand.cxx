/**
 * @file codificarImagenCommand.cxx
 * @brief Implementación del comando encargado de códificar una imagen cargada
 * previamente en memoria
 *
 * Este archivo contiene la implementación de la función
 * `handlerCodificarImagen`, que genera un archivo binario que contiene la
 * imagen codificada usando el algoritmo Huffman.
 */

#include <bits/stdc++.h>

#include <fstream>

#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../core/huffman/Huffman.h"
#include "../utils/guardarImagenHuff.h"

using namespace std;

/**
 * @brief Códifica y genera el archivo binario de una imagen cargada previamente
 * en memoria haciendo uso del algoritmo Huffman
 *
 * @param argv Vector de strings que contiene los argumentos del usuario.
 *        - `argv[0]`: Nombre del programa (ignorado).
 *        - `argv[1]`: (Obligatorio) Nombre del archivo destino donde se
 * guardará el contenido binario que se genera a partir de la codificación de
 * Huffman.
 *
 * @param memoria Memoria del sistema
 *
 * @return 0 si la ejecución fue exitosa.
 */

int handlerCodificarImagen(vector<string> argv, Memoria &memoria) {
  Imagen *img = memoria.getImagenEnMemoria();

  if (img == nullptr) {
    cout << "No hay una imagen cargada en memoria" << endl;
    return 0;
  }

  Huffman h;

  cout << "Codificando imagen..." << endl;

  h.genTree(img->getMaxIntensidad(), img->getContenido());

  // h.writeGraph();
  cout << "Guardando archivo " << argv[1] << endl;

  try {
    guardarImagenHUFF(img, h.getReps(), h.encode(img->getContenido()), argv[1]);
    cout << "El archivo se ha guardado con exito" << endl;
    return 0;
  } catch (const std::exception &err) {
    cerr << "Error: " << err.what();
    return 1;
  }
}

Comando CommandManager::codificarImagenCommand = *(new Comando(
    {"codificar_imagen", 2, [](vector<string> args, Memoria &memoria) {
       return handlerCodificarImagen(args, memoria);
     }}));