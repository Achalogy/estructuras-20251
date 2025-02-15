#include <bits/stdc++.h>
#include <fstream>
#include "commandManager.h"

using namespace std;

int dummyProyeccion2D(vector<string> argv)
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

Command CommandManager::proyeccion2DCommand = *(
    new Command({"proyeccion2D",
                 4,
                 [](vector<string> args)
                 {
                   return dummyProyeccion2D(args);
                 }}));