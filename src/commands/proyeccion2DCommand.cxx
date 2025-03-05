#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/proyectarVolumen.h"
#include "../utils/guardarImagenPGM.h"

using namespace std;


int handlerProyeccion2D(vector<string> argv, Memoria &memoria)
{
  Volumen *vol = memoria.getVolumenEnMemoria();

  if (vol == nullptr)
  {
    cout << "No hay un volumen cargado en memoria" << endl;
    return 0;
  }

  try {
    Imagen *img = proyectarVolumen(memoria.getVolumenEnMemoria(), argv[1][0], argv[2][0]);

    std::cout << "Proyeccion generado con exito, guardando archivo..." << std::endl;

    guardarImagenPGM(img, argv[3]);

    std::cout << "Archivo " << argv[3] << " guardado con exito" << std::endl;
  } catch(const std::exception &err) {
    std::cerr << "Error: " << err.what() << std::endl;
    return 1;
  }

  return 0;
}

Comando CommandManager::proyeccion2DCommand = *(
    new Comando({"proyeccion2D",
                 4,
                 [](vector<string> args, Memoria &memoria)
                 {
                     return handlerProyeccion2D(args, memoria);
                 }}));