#include <bits/stdc++.h>

#include "../core/TADImagen.h"

void guardarImagenPGM(Imagen *img, std::string path) {
  std::ofstream archivo(path);

  if (!archivo.is_open())
    throw std::runtime_error("No se pudo acceder a " + path);

  int ancho = img->getAncho();
  int alto = img->getAlto();

  archivo << "P2" << std::endl;
  archivo << ancho << " " << alto << std::endl;
  archivo << img->getMaxIntensidad() << std::endl;

  std::vector<std::vector<int>> &contenido = img->getContenido();

  for (int i = 0; i < alto; i++) {
    for (int j = 0; j < ancho; j++) {
      int value = contenido[i][j];

      archivo << value;

      if (j != ancho - 1) archivo << " ";
    }

    if (i != alto - 1) archivo << std::endl;
  }

  archivo.close();
}