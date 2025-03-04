/**
 * @file TADVolumen.cxx
 * @brief Implementaciones de TADVolumen.h
 */

#include <bits/stdc++.h>

#include "TADVolumen.h"
#include "TADImagen.h"

Volumen::Volumen(std::string r_baseName, std::vector<Imagen> r_imagenes)
{
  int r_n_im = r_imagenes.size();

  if (r_n_im >= 99 || r_n_im < 0)
    throw std::out_of_range("Cantidad de imagenes invalida, debe ser un número entre (1 - 99)");

  n_im = r_n_im;
  imagenes = r_imagenes;
  baseName = r_baseName;
  if(r_imagenes.size() > 0) {
    altura = (unsigned short) r_imagenes[0].getAlto();
    ancho = (unsigned short) r_imagenes[0].getAncho();
  } else {
    altura = 0;
    ancho = 0;
  }
}

std::vector<Imagen> Volumen::getImagenes()
{
  return imagenes;
}

Imagen Volumen::getImagen(unsigned int n_imagen)
{
  if (n_imagen < imagenes.size())
    return imagenes[n_imagen];
  else
    throw std::runtime_error("Error al intentar leer la imagen, no existe una imagen en la posicion " + n_imagen);
}

unsigned int Volumen::getNumeroImagenes()
{
  return n_im;
}
