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
    altura =  r_imagenes[0].getAlto();
    ancho =  r_imagenes[0].getAncho();
  } else {
    altura = 0;
    ancho = 0;
  }
}

std::vector<Imagen> Volumen::getImagenes()
{
  return imagenes;
}

int Volumen::getNumeroImagenes()
{
  return n_im;
}

std::string Volumen::getBaseName() {
  return baseName;
}

int Volumen::getAltura() {
  return altura;
}

int Volumen::getAncho() {
  return ancho;
}