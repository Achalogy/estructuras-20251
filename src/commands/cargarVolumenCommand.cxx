#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyCargarVolumen(vector<string> argv)
{


  return 0;
}

Command CommandManager::cargarVolumenCommand = *(
    new Command({"cargar_volumen",
                 3,
                 [](vector<string> args)
                 {
                   return dummyCargarVolumen(args);
                 }}));