#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validDecodificarImagen = false;

int handlerDecodificarArchivo(vector<string> argv, Memoria memoria)
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

Comando CommandManager::decodificarArchivoCommand = *(
    new Comando({"decodificar_archivo",
                 3,
                 [](vector<string> args, Memoria memoria)
                 {
                     return handlerDecodificarArchivo(args, memoria);
                 }}));