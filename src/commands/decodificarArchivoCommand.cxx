#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyDecodificarArchivo(vector<string> argv)
{

  return 0;
}

Command CommandManager::decodificarArchivoCommand = *(
    new Command({"decodificar_archivo",
                 3,
                 [](vector<string> args)
                 {
                   return dummyDecodificarArchivo(args);
                 }}));