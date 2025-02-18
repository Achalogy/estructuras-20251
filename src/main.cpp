/**
 * @file main.cpp
 * @brief Programa principal
 */

#include <bits/stdc++.h>
#include "commands/commandManager.h"

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
  CommandManager *cm = new CommandManager();
  vector<string> argv;

  while(true)
  {
    argv = cm->getNextLine();

    // cout << "Comando " << argv[0] << " ejecutado" << endl;
    cm->ejecutarComando(argv);
  }

  return 0;
}