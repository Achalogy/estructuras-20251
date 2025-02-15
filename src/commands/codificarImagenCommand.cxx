#include <bits/stdc++.h>
#include <fstream>
#include "commandManager.h"

using namespace std;

int dummyCodificarImagen(vector<string> argv)
{
    ifstream file;
    file.exceptions ( ifstream::badbit );

    try {
        file.open(argv[1]);
    }
    catch (const ifstream::failure& e) {
        cout << endl << "No se ha podido leer el archivo" << endl;
    }

    file.close();
    return 0;
}

Command CommandManager::codificarImagenCommand = *(
    new Command({"codificar_imagen",
                 2,
                 [](vector<string> args)
                 {
                   return dummyCodificarImagen(args);
                 }}));