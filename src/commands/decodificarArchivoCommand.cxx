#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/leerImagenHuff.h"
#include "../utils/guardarImagenPGM.h"

using namespace std;

int handlerDecodificarArchivo(vector<string> argv, Memoria &memoria)
{
  try
  {
    cout << "Comenzando a cargar el archivo..." << endl;
    Imagen *imagen = leerImagenHuff(argv[1]);
    memoria.setImagenEnMemoria(imagen);

    cout << "Se ha finalizado la carga y dedodificacion del archivo " << argv[1] << endl;

    guardarImagenPGM(imagen, argv[2]);

    std::cout << "Archivo " << argv[2] << " guardado con exito" << std::endl;
    return 0;
  } catch (const std::exception &err) {
    std::cerr << "ERROR " << argv[1] << ": " << err.what() << endl;
    return 1;
  }
}

Comando CommandManager::decodificarArchivoCommand = *(
    new Comando({"decodificar_archivo",
                 3,
                 [](vector<string> args, Memoria &memoria)
                 {
                   return handlerDecodificarArchivo(args, memoria);
                 }}));