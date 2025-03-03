#include <bits/stdc++.h>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

int handlerSalir(vector<string> argv, Imagen *imagenEnMemoria)
{
  exit(0);
  return 0;
}

Comando CommandManager::salirCommand = *(
    new Comando({"salir",
                 1,
                 [](vector<string> args, Imagen *imagenEnMemoria)
                 {
                   return handlerSalir(args, imagenEnMemoria);
                 }}));