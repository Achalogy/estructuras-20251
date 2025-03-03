#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"

using namespace std;

int dummyCargarImagen(vector<string> argv)
{
    ifstream file(argv[1]);

    if (file.is_open())
    {
        cout << "La imagen " << argv[1] << " ha sido cargada" << endl;
        file.close();
        return 0;
    }
    else
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
