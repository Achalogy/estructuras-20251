#include <bits/stdc++.h>
#include "commandManager.h"

using namespace std;

int dummyAyuda(vector<string> argv)
{

  if (argv.size() == 1)
  { // Ayuda general

    cout << "v0.0.1" << endl;
    cout << "Usa `ayuda` para ver esta lista" << endl;
    cout << "Usa `ayuda comando` para encontrar mas informacion sobre `comando`" << endl
         << endl;

    cout << "cargar_imagen [imagen.pgm]" << endl;
    cout << "cargar_volumen [nombre_base] [n_im]" << endl;
    cout << "info_imagen" << endl;
    cout << "info_volumen" << endl;
    cout << "proyeccion2D [direccion] [criterio] [imagen.pgm]" << endl;
    cout << "codificar_imagen [archivo.huf]" << endl;
    cout << "decodificar_imagen [archivo.huf] [imagen.pgm]" << endl;
    cout << "segmentar [imagen.pgm] [sx1 sy1 sl1 ... sxn syn sln]" << endl;
    cout << "salir" << endl;
  }
  else
  {
    string command = argv[1];


  }

  return 0;
}

Command CommandManager::ayudaCommand = *(
    new Command({"ayuda",
                 1,
                 [](vector<string> args)
                 {
                   return dummyAyuda(args);
                 }}));