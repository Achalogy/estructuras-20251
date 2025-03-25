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

    cout << "Codificando imagen..." << endl;

    h.genTree(img->getContenido());

    // h.writeGraph();
    cout << "Guardando archivo " << argv[1] << endl;

    try
    {
        guardarImagenHUFF(
            img,
            h.getReps(),
            h.encode(img->getContenido()),
            argv[1]);
        cout << "El archivo se ha guardado con exito" << endl;
        return 0;
    }
    catch (const std::exception &err)
    {
        cerr << "Error: " << err.what();
        return 1;
    }
}

Comando CommandManager::codificarImagenCommand = *(
    new Comando({"codificar_imagen",
                 2,
                 [](vector<string> args, Memoria &memoria)
                 {
                     return handlerCodificarImagen(args, memoria);
                 }}));