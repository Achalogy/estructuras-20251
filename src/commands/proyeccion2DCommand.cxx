#include <bits/stdc++.h>
#include <fstream>
#include "commandManager.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool valid = false;

int dummyProyeccion2D(vector<string> argv)
{
    if (valid)
    {
        cout << "La proyeccion 2D del volumen en memoria ha sido generada y almacenada en el archivo nombre_archivo.pgm" << endl;
            return 0;
    }
    else
    {
        cout << "El volumen no ha sido cargado en memoria" << endl;
        cout << "La proyeccion 2D no pudo ser generada" << endl;
        return 1;
    }
}

Command CommandManager::proyeccion2DCommand = *(
    new Command({"proyeccion2D",
                 4,
                 [](vector<string> args)
                 {
                   return dummyProyeccion2D(args);
                 }}));