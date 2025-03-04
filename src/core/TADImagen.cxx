/**
 * @file TADImagen.cxx
 * @brief Implementaciones de TADImagen.h
 */

#include <bits/stdc++.h>

#include "TADImagen.h"

Imagen::Imagen(std::string r_path, unsigned int r_ancho, unsigned int r_alto, unsigned short r_max_intensidad, std::vector<std::vector<unsigned short>> r_contenido)
{
  // Verificar valores
  if (r_ancho < 0 || r_alto < 0)
    throw std::out_of_range("Dimensiones invalidas");
  if (r_max_intensidad < 0 || r_max_intensidad > 255)
    throw std::out_of_range("Intensidad maxima invalida, debe estar entre 0 y 255");

  // Verificar contenido

  bool matriz_invalida = r_contenido.size() != r_alto;

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

  ancho = r_ancho;
  alto = r_alto;
  contenido = r_contenido;
  path = r_path;
}

unsigned int Imagen::getAlto()
{
  return alto;
}
unsigned int Imagen::getAncho()
{
  return ancho;
}
unsigned short Imagen::getMaxIntensidad()
{
  return max_intensidad;
}
std::vector<std::vector<unsigned short>> Imagen::getContenido()
{
  return contenido;
}
std::string Imagen::getPath() {
  return path;
}