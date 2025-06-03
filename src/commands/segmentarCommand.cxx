#include <bits/stdc++.h>

#include "../core/TADCommandManager.h"
#include "../core/TADImagen.h"
#include "../utils/genSegmentedImg.h"
#include "../utils/guardarImagenPGM.h"

#define endl "\n"

using namespace std;

int handlerSegmentar(vector<string> argv, Memoria &memoria) {
  Imagen *img = memoria.getImagenEnMemoria();

  if (img == nullptr) {
    cout << "No hay una imagen cargada en memoria" << endl;
    return 0;
  }

  int cantSemillas = min(5, (int)(argv.size() - 2) / 3);

  vector<Semilla> semillas;

  try {
    for (int i = 0; i < cantSemillas; i++) {
      char *token;
      unsigned char tag =
          (unsigned char)strtol(argv[4 + (i * 3)].c_str(), &token, 10);

      if (*token != '\0') {
        throw runtime_error("El tag en la semilla " + to_string(i + 1) +
                            " es incorrecto");
      }

      token = NULL;

      unsigned int y =
          (unsigned char)strtol(argv[3 + (i * 3)].c_str(), &token, 10);

      if (*token != '\0') {
        throw runtime_error("La coordenada y tiene un valor no numérico");
      }

      token = NULL;

      unsigned int x =
          (unsigned char)strtol(argv[2 + (i * 3)].c_str(), &token, 10);

      if (*token != '\0') {
        throw runtime_error("La coordenada x tiene un valor no numérico");
      }

      cout << "Semilla " << i + 1 << "  - ";
      cout << " tag: " << (int)tag;
      cout << " y: " << y;
      cout << " x: " << x << endl;

      if (y < 0 || y > img->getAlto() || x < 0 || x > img->getAncho()) {
        throw runtime_error("La semilla tiene unas coordenadas invalidas");
      }

      if (tag < 1 || tag > 255) {
        throw runtime_error("La semilla tiene un tag invalido (0-255)");
      }

      semillas.push_back(Semilla(tag, x, y));
    }

    cout << "Semillas leidas correctamente" << endl;
    Imagen *sImg = genSegmentedImg(img, semillas);

    guardarImagenPGM(sImg, argv[1]);
  } catch (const exception &err) {
    std::cerr << "Error: " << err.what() << endl;
    return 1;
  }

  cout << "Se ha terminado de segmentar la imagen y se ha guardado en "
       << argv[1] << endl;

  return 0;
}

Comando CommandManager::segmentarCommand =
    *(new Comando({"segmentar", 5, [](vector<string> args, Memoria &memoria) {
                     return handlerSegmentar(args, memoria);
                   }}));