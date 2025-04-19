#include <bits/stdc++.h>

#include <fstream>

#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/guardarImagenPGM.h"
#include "../utils/leerImagenHuff.h"

using namespace std;

int handlerDecodificarArchivo(vector<string> argv, Memoria &memoria) {
  Imagen *imagen = NULL;

  try {
    cout << "Comenzando a cargar el archivo..." << endl;
    Imagen *imagen = leerImagenHuff(argv[1]);
    memoria.setImagenEnMemoria(imagen);

    cout << "Se ha finalizado la carga y dedodificacion del archivo " << argv[1]
         << endl;

    guardarImagenPGM(imagen, argv[2]);

    if (imagen != NULL) delete imagen;

    std::cout << "Archivo " << argv[2] << " guardado con exito" << std::endl;
    return 0;
  } catch (const std::exception &err) {
    if (imagen != NULL) delete imagen;
    std::cerr << "ERROR " << argv[1] << ": " << err.what() << endl;
    return 1;
  }
}

Comando CommandManager::decodificarArchivoCommand = *(new Comando(
    {"decodificar_archivo", 3, [](vector<string> args, Memoria &memoria) {
       return handlerDecodificarArchivo(args, memoria);
     }}));