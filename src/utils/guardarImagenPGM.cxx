#include <bits/stdc++.h>
#include "../core/TADImagen.h"

void guardarImagenPGM(Imagen *img, std::string path)
{
  std::ofstream archivo(path);

  if (!archivo.is_open())
    throw std::runtime_error("No se pudo acceder a " + path);

  archivo << "P2" << std::endl;
  archivo << img->getAncho() << " " << img->getAlto() << std::endl;
  archivo << img->getMaxIntensidad() << std::endl;

  for (std::vector<int> v : img->getContenido())
  {
    for (int i : v)
    {
      archivo << i << " ";
    }
    archivo << std::endl;
  }

  archivo.close();
}