/**
 * @file infoVolumenCommand.cxx
 * @brief Implementación del comando info_volumen
 */

#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

/**
 * @brief Revisa si existe un volumen cargado en memoria, si es así muestra su información
 * @param argv Vector de strings que contiene los argumentos del usuario. (Ignorado)
 * @param memoria Memoria del sistema
 * @return 0 si la ejecución fue exitosa
 */
int handlerInfoVolumen(vector<string> argv, Memoria &memoria)
{
  Volumen *vol = memoria.getVolumenEnMemoria();

  if(vol == nullptr) {
    cout << "No hay un volumen cargado en memoria" << endl;
    return 0;
  }

  cout << "Volumen cargado en memoria: " << vol->getBaseName() << endl;
  cout << "  Tamano: " << vol->getNumeroImagenes() << endl;
  cout << "  Ancho:  " << vol->getAncho() << endl;
  cout << "  Alto:   " << vol->getAltura() << endl;
  
  return 0;
}

Comando CommandManager::infoVolumenCommand = *(
    new Comando({"info_volumen",
                 1,
                 [](vector<string> args, Memoria &memoria)
                 {
                   return handlerInfoVolumen(args, memoria);
                 }}));