#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validCodificarImagen = false;

int handlerCodificarImagen(vector<string> argv, Imagen *imagenEnMemoria)
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

Comando CommandManager::codificarImagenCommand = *(
    new Comando({"codificar_imagen",
                 2,
                 [](vector<string> args, Imagen *imagenEnMemoria)
                 {
                     return handlerCodificarImagen(args, imagenEnMemoria);
                 }}));