#include <bits/stdc++.h>
#include <fstream>
#include "commandManager.h"

using namespace std;

int dummyCargarVolumen(vector<string> argv)
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

Command CommandManager::cargarVolumenCommand = *(
    new Command({"cargar_volumen",
                 3,
                 [](vector<string> args)
                 {
                   return dummyCargarVolumen(args);
                 }}));