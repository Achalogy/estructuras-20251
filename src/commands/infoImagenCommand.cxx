#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyInfoImagen(vector<string> argv)
{

  return 0;
}

Command CommandManager::infoImagenCommand = *(
    new Command({"info_imagen",
                 1,
                 [](vector<string> args)
                 {
                   return dummyInfoImagen(args);
                 }}));