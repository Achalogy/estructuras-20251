#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/leerVolumen.h"

using namespace std;

int handlerCargarVolumen(vector<string> argv, Memoria memoria)
{
  char *endptr;
  long n_im = std::strtol(argv[2].c_str(), &endptr, 10);

  try
  {
    if (*endptr != '\0')
      throw std::runtime_error("Formato invalido para la cantidad de imagenes");

    Volumen *volumen = leerVolumen(argv[1], (int)n_im);

    memoria.setVolumenEnMemoria(volumen);

    cout << "Se ha finalizado la cargar del volumen " << argv[1] << endl;

    return 0;
  }
  catch (const std::exception &err)
  {
    std::cerr << "ERROR cargando volumen " << argv[1] << ": " << err.what() << std::endl;
    return 1;
  }
}

Comando CommandManager::cargarVolumenCommand = *(
    new Comando({"cargar_volumen",
                 3,
                 [](vector<string> args, Memoria memoria)
                 {
                   return handlerCargarVolumen(args, memoria);
                 }}));