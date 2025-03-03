#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validInfoVolumen = false;

int dummyInfoVolumen(vector<string> argv)
{
    if (validInfoVolumen)
    {
        cout << "Volumen cargado en memoria: nombre_base, tamaño: n_im, ancho: W, alto: H" << endl;
        return 0;
    }
    else
    {
        cout << "No hay volumen cargado en memoria" << endl;
        return 1;
    }
}

Command CommandManager::infoVolumenCommand = *(
    new Command({"info_volumen",
                 1,
                 [](vector<string> args)
                 {
                   return dummyInfoVolumen(args);
                 }}));