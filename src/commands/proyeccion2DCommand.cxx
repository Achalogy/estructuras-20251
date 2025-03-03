#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validProyeccion2D = false;

int handlerProyeccion2D(vector<string> argv, Imagen *imagenEnMemoria)
{
    if (validProyeccion2D)
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

Comando CommandManager::proyeccion2DCommand = *(
    new Comando({"proyeccion2D",
                 4,
                 [](vector<string> args, Imagen * imagenEnMemoria)
                 {
                     return handlerProyeccion2D(args, imagenEnMemoria);
                 }}));