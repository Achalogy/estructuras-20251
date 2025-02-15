#include <bits/stdc++.h>
#include "commandManager.h"
#include <fstream>

using namespace std;

int dummyCargarImagen(vector<string> argv)
{
    ifstream file;

    file.open(argv[1]);
    if (!file)
    {
        return 1;
    }
    return 0;
}

Command CommandManager::cargarImagenCommand = *(
    new Command({"cargar_imagen",
                 2,
                 [](vector<string> args)
                 {
                   return dummyCargarImagen(args);
                 }}));
