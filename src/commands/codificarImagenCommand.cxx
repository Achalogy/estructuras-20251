#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyCodificarImagen(vector<string> argv)
{

  return 0;
}

Command CommandManager::codificarImagenCommand = *(
    new Command({"codificar_imagen",
                 2,
                 [](vector<string> args)
                 {
                   return dummyCodificarImagen(args);
                 }}));