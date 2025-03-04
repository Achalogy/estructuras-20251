#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

int handlerInfoVolumen(vector<string> argv, Memoria &memoria)
{
  Volumen *vol = memoria.getVolumenEnMemoria();

  if(vol == nullptr) {
    cout << "No hay un volumen cargado en memoria" << endl;
    return 0;
  }

  cout << "Volumen cargado en memoria: " << vol->getBaseName() << endl;
  cout << "  Tamano: " << vol->getNumeroImagenes() << endl;
  cout << "  Ancho:  " << vol->getAncho() << endl;
  cout << "  Alto:   " << vol->getAltura() << endl;
  
  return 0;
}

Comando CommandManager::infoVolumenCommand = *(
    new Comando({"info_volumen",
                 1,
                 [](vector<string> args, Memoria &memoria)
                 {
                   return handlerInfoVolumen(args, memoria);
                 }}));