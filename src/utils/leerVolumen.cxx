/**
 * @file leerVolumen.cxx
 * @brief Implementación de leerVolumen.h
 */

#include "leerVolumen.h"

#include <bits/stdc++.h>

#define endl "\n"

Volumen *leerVolumen(std::string baseName, int n_im) {
  if (n_im < 1 || n_im > 99)
    throw std::runtime_error("Cantidad de imagenes fuera de rango (1-99)");

  std::vector<Imagen> imagenes;

  for (int i = 1; i <= n_im; i++) {
    std::string filename = baseName;

    if (i <= 9) filename += "0";

    filename += std::to_string(i) + ".pgm";

    std::cout << "Leyendo la imagen " << filename << " (" << i << "/" << n_im
              << ")" << endl;
    try {
      Imagen *img = leerImagenPGM(filename);

      if (imagenes.size() > 0)
        if (imagenes[0].getAlto() != img->getAlto() ||
            imagenes[0].getAncho() != img->getAncho())
          throw std::runtime_error(
              "La imagen leida tiene un tamaño diferente a las demas");

      imagenes.push_back(*img);
    } catch (const std::exception &err) {
      throw std::runtime_error("Error leyendo " + filename + ": \n  " +
                               err.what());
    }
  }

  Volumen *v = new Volumen(baseName, imagenes);

  return v;
}