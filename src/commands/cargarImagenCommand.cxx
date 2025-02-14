#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyCargarImagen(vector<string> argv)
{

  return 0;
}

Command CommandManager::cargarImagenCommand = *(
    new Command({"cargar_imagen",
                 2,
                 [](vector<string> args)
                 {
                   return dummyCargarImagen(args);
                 }}));