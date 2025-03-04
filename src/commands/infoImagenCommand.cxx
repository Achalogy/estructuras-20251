#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

int handlerInfoImagen(vector<string> argv, Memoria &memoria)
{
  Imagen *img = memoria.getImagenEnMemoria();

  cout << img << endl;

  if (img == nullptr) {
    cout << "No hay una imagen cargada en memoria" << endl;
    return 0;
  }

  cout << "Imagen cargada en memoria: " << img->getPath() << endl;
  cout << "  Ancho: " << img->getAncho() << endl;
  cout << "  Alto: " << img->getAlto() << endl;
  
  return 0;
}

Comando CommandManager::infoImagenCommand = *(
    new Comando({"info_imagen",
                 1,
                 [](vector<string> args, Memoria &memoria)
                 {
                   return handlerInfoImagen(args, memoria);
                 }}));