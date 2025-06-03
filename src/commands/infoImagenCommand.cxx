/**
 * @file infoImagenCommand.cxx
 * @brief Implementación del comando info_imagen
 */

#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

#define endl "\n"

using namespace std;

/**
 * @brief Revisa si existe una imagen cargada en memoria, si es así muestra su información
 * @param argv Vector de strings que contiene los argumentos del usuario. (Ignorado)
 * @param memoria Memoria del sistema
 * @return 0 si la ejecución fue exitosa
 */
int handlerInfoImagen(vector<string> argv, Memoria &memoria)
{
  Imagen *img = memoria.getImagenEnMemoria();

  if (img == nullptr) {
    cout << "No hay una imagen cargada en memoria" << endl;
    return 0;
  }

  cout << "Imagen cargada en memoria: " << img->getPath() << endl;
  cout << "  Ancho: " << img->getAncho() << endl;
  cout << "  Alto:  " << img->getAlto() << endl;
  
  return 0;
}

Comando CommandManager::infoImagenCommand = *(
    new Comando({"info_imagen",
                 1,
                 [](vector<string> args, Memoria &memoria)
                 {
                   return handlerInfoImagen(args, memoria);
                 }}));