#include <bits/stdc++.h>
#include <fstream>
#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../core/huffman/Huffman.h"
#include "../utils/guardarImagenHuff.h"

using namespace std;

int handlerCodificarImagen(vector<string> argv, Memoria &memoria)
{
    Imagen *img = memoria.getImagenEnMemoria();

    if (img == nullptr)
    {
        cout << "No hay una imagen cargada en memoria" << endl;
        return 0;
    }

    Huffman h;

    h.genTree(img->getContenido());

    // h.writeGraph();

    guardarImagenHUFF(
        img,
        h.getReps(),
        h.encode(img->getContenido()),
        argv[1]);
    return 0;
}

Comando CommandManager::codificarImagenCommand = *(
    new Comando({"codificar_imagen",
                 2,
                 [](vector<string> args, Memoria &memoria)
                 {
                     return handlerCodificarImagen(args, memoria);
                 }}));