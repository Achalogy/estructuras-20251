#include <bits/stdc++.h>
#include <fstream>
#include "commandManager.h"

using namespace std;

int dummyCargarImagen(vector<string> argv)
{
    ifstream file;
    file.exceptions(ifstream::badbit);

    try
    {
        file.open(argv[1]);

        cout << "La imagen " << argv[1] << " ha sido cargada" << endl;
        file.close();
        return 0;
    }
    catch (const ifstream::failure &e)
    {
        cout << "La imagen " << argv[1] << " no ha podido ser cargada" << endl;
        file.close();
        return 1;
    }
}

Command CommandManager::cargarImagenCommand = *(
    new Command({"cargar_imagen",
                 2,
                 [](vector<string> args)
                 {
                     return dummyCargarImagen(args);
                 }}));
