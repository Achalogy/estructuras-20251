#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validinfoImagen = false;

int handlerInfoImagen(vector<string> argv)
{
    if (validinfoImagen)
    {
        cout << "Imagen cargada en memoria: imagen_ejemplo.pgm, ancho: W, alto: H" << endl;
        return 0;
    }
    else
    {
        cout << "No hay imagen cargada en memoria" << endl;
        return 1;
    }

}

Command CommandManager::infoImagenCommand = *(
    new Command({"info_imagen",
                 1,
                 [](vector<string> args)
                 {
                     return handlerInfoImagen(args);
                 }}));