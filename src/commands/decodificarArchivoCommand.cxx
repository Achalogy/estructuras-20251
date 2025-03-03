#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validDecodificarImagen = false;

int handlerDecodificarArchivo(vector<string> argv)
{
    if (validDecodificarImagen)
    {
        cout << "El archivo nombre_archivo.huf ha sido decodificado exitosamente y almacenado en nombre_imagen.pgm" << endl;
        return 0;
    }
    else
    {
        cout << "El archivo nombre_archivo.huf no pudo ser decodificado" << endl;
        return 1;
    }
}

Command CommandManager::decodificarArchivoCommand = *(
    new Command({"decodificar_archivo",
                 3,
                 [](vector<string> args)
                 {
                   return handlerDecodificarArchivo(args);
                 }}));