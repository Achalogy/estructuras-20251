#include <bits/stdc++.h>

#include "TADImagen.h"

Imagen::Imagen(unsigned short r_ancho, unsigned short r_alto, unsigned short r_max_intensidad, std::vector<std::vector<unsigned short>> r_contenido)
{
  // Verificar valores
  if (r_ancho < 0 || r_alto < 0)
    throw std::out_of_range("Dimensiones invalidas");
  if (r_max_intensidad < 0 || r_max_intensidad > 255)
    throw std::out_of_range("Intensidad maxima invalida, debe estar entre 0 y 255");

  // Verificar contenido

  bool matriz_invalida = r_contenido.size() == r_alto;

  for (std::vector<unsigned short> i : r_contenido)
  {
    if (matriz_invalida)
      break;

    if (i.size() != r_ancho)
      matriz_invalida = true;
  }

  if (matriz_invalida)
    throw std::invalid_argument("La dimension de la matriz no concuerda con los datos de alto y ancho");

  // Datos verificados

  this->ancho = r_ancho;
  this->alto = r_alto;
  this->contenido = r_contenido;
}

unsigned short Imagen::getAlto()
{
  return this->alto;
}
unsigned short Imagen::getAncho()
{
  return this->ancho;
}
unsigned short Imagen::getMaxIntensidad()
{
  return this->max_intensidad;
}
std::vector<std::vector<unsigned short>> Imagen::getContenido()
{
  return this->contenido;
}