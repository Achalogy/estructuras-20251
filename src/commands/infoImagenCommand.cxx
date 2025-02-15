#include <bits/stdc++.h>
#include <fstream>
#include "commandManager.h"

using namespace std;

int dummyInfoImagen(vector<string> argv)
{
    ifstream file;
    file.exceptions ( ifstream::badbit );

    try {
        file.open(argv[1]);
    }
    catch (const ifstream::failure& e) {
        cout << endl << "No se ha podido leer el archivo " << argv[1] << endl;
    }

    file.close();
    return 0;
}

Command CommandManager::infoImagenCommand = *(
    new Command({"info_imagen",
                 1,
                 [](vector<string> args)
                 {
                   return dummyInfoImagen(args);
                 }}));