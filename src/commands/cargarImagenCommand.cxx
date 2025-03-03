#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

int handlerCargarImagen(vector<string> argv, Imagen *imagenEnMemoria)
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

Comando CommandManager::cargarImagenCommand = *(
    new Comando({"cargar_imagen",
                 2,
                 [](vector<string> args, Imagen *imagenEnMemoria)
                 {
                     return handlerCargarImagen(args, imagenEnMemoria);
                 }}));
