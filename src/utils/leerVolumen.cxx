#include <bits/stdc++.h>

#include "leerVolumen.h"

Volumen *leerVolumen(std::string baseName, int n_im)
{
  std::vector<Imagen> imagenes;

  for (int i = 1; i <= n_im; i++)
  {
    std::string filename = baseName;

    if (i <= 9)
      filename += "0";

    filename += std::to_string(i) + ".pgm";

    std::cout << "Leyendo la imagen " << filename << " (" << i << "/" << n_im << ")" << std::endl;
    try
    {
      imagenes.push_back(*leerImagenPGM(filename));
    }
    catch (const std::exception &err)
    {
      throw std::runtime_error("Error leyendo " + filename + ": " + err.what());
    }
  }

  Volumen *v = new Volumen(
      imagenes);

  return v;
}