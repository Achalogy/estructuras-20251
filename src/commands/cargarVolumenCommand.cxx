#include <bits/stdc++.h>
#include <fstream>
#include "commandManager.h"

using namespace std;

int dummyCargarVolumen(vector<string> argv)
{
    string nombre_base = argv[1];
    int n = stoi(argv[2]);

    bool validCargarVolumen = true;

    for (int i = 1; i <= n && validCargarVolumen; i++)
    {
        string filename = nombre_base + to_string(i) + ".pgm";
        ifstream file(filename);

        if(file.is_open())
        {
            cout << "El archivo " << filename << " ha sido cargado con exito" << endl;
        } else {
            cout << "El archivo " << filename << " no ha podido ser cargado, finalizando carga" << endl;
            validCargarVolumen = false;
        }

        file.close();
    }

    if (validCargarVolumen)
    {
        cout << "El volumen " << argv[1] << " ha sido cargado con exito" << endl;
        return 0;
    }
    else
    {
        cout << "El volumen " << argv[1] << " no ha podido ser cargado" << endl;
        return 1;
    }
}

Command CommandManager::cargarVolumenCommand = *(
    new Command({"cargar_volumen",
                 3,
                 [](vector<string> args)
                 {
                     return dummyCargarVolumen(args);
                 }}));