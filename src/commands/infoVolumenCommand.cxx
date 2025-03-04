#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"

using namespace std;

// SWITCH DE PRIMER ENTREGA

bool validInfoVolumen = false;

int handlerInfoVolumen(vector<string> argv, Memoria &memoria)
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

Comando CommandManager::infoVolumenCommand = *(
    new Comando({"info_volumen",
                 1,
                 [](vector<string> args, Memoria &memoria)
                 {
                     return handlerInfoVolumen(args, memoria);
                 }}));