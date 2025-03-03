/**
 * @file main.cpp
 * @brief Programa principal
 */

#include <bits/stdc++.h>
#include "./core/TADSistema.h"

using namespace std;

/**
 * @brief Funcion principal del programa
 * 
 * Inicializa el Command Manager y permite al usuario interacturar con el sistema.
 * 
 * Lee una a una las lineas de comando enviadas por el usuario y las ejecuta.
 * 
 * @return 0 si la ejecución fue exitosa
 */

int main()
{
  Sistema sys;
  vector<string> argv;

  while(true)
  {
    argv = sys.getNextLine();

    sys.ejecutarComando(argv);
  }

  return 0;
}