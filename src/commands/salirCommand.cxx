#include <bits/stdc++.h>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

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