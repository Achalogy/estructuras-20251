#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/leerImagenPGM.h"

using namespace std;

int handlerCargarImagen(vector<string> argv, Memoria &memoria)
{
  try
  {
    Imagen *imagen = leerImagenPGM(argv[1]);
    memoria.setImagenEnMemoria(imagen);

    cout << "Se ha finalizado la carga del archivo " << argv[1] << endl;

    return 0;
  }
  catch (const std::exception& err)
  {
    std::cerr << "ERROR " << argv[1] << ": " << err.what() << endl;
    return 1;
  }
}

Comando CommandManager::cargarImagenCommand = *(
    new Comando({"cargar_imagen",
                 2,
                 [](vector<string> args, Memoria &memoria)
                 {
                   return handlerCargarImagen(args, memoria);
                 }}));
