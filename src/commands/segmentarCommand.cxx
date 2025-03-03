#include <bits/stdc++.h>
#include "../core/TADCommandManager.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validSegmentar = false;

int handlerSegmentar(vector<string> argv)
{
  if (validSegmentar)
  {
    cout << "La imagen en memoria fue segmentada correctamente y almacenada en salida_imagen.pgm" << endl;
    return 0;
  }
  else
  {
    cout << "No hay imagen cargada en memoria" << endl;
    cout << "La segmentacion no pudo ser realizada" << endl;
    return 1;
  }

  return 0;
}

Command CommandManager::segmentarCommand = *(
    new Command({"segmentar",
                 5,
                 [](vector<string> args)
                 {
                   return handlerSegmentar(args);
                 }}));