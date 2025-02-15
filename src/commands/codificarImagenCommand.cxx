#include <bits/stdc++.h>
#include <fstream>
#include "commandManager.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validCodificarImagen = false;

int dummyCodificarImagen(vector<string> argv)
{
    if (validCodificarImagen)
    {
        cout << "La imagen en memoria ha sido codificada y almacenada en nombre_archivo.huf" << endl;
        return 0;
    }
    else
    {
        cout << "No hay una imagen cargada en memoria" << endl;
        return 1;
    }
}

Command CommandManager::codificarImagenCommand = *(
    new Command({"codificar_imagen",
                 2,
                 [](vector<string> args)
                 {
                   return dummyCodificarImagen(args);
                 }}));