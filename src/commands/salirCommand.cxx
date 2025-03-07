/**
 * @file salirCommand.cxx
 * @brief Implementación del comando salir
 */
#include <bits/stdc++.h>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

/**
 * @brief Terminar de ejecutar el comando y sale con el código 0 (sin errores)
 * @param argv Vector de strings que contiene los argumentos del usuario. (Ignorado)
 * @param memoria Memoria del sistema
 * @return 0 si la ejecución fue exitosa
 */
int handlerSalir(vector<string> argv, Memoria &memoria)
{
  exit(0);
  return 0;
}

Comando CommandManager::salirCommand = *(
    new Comando({"salir",
                 1,
                 [](vector<string> args, Memoria &memoria)
                 {
                   return handlerSalir(args, memoria);
                 }}));