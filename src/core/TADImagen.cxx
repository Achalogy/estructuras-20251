/**
 * @file TADImagen.cxx
 * @brief Implementaciones de TADImagen.h
 */

#include <bits/stdc++.h>

#include "TADImagen.h"

Imagen::Imagen(std::string r_path, int r_ancho, int r_alto, int r_max_intensidad, std::vector<std::vector<int>> r_contenido)
{
  // Verificar valores
  if (r_ancho < 0 || r_alto < 0)
    throw std::out_of_range("Dimensiones invalidas");
  if (r_max_intensidad < 0 || r_max_intensidad > 255)
    throw std::out_of_range("Intensidad maxima invalida, debe estar entre 0 y 255");

  // Verificar contenido

  bool matriz_invalida = r_contenido.size() != r_alto;

  for (std::vector<int> i : r_contenido)
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
  max_intensidad = r_max_intensidad;
}

int Imagen::getAlto()
{
  return alto;
}
int Imagen::getAncho()
{
  return ancho;
}
int Imagen::getMaxIntensidad()
{
  return max_intensidad;
}
std::vector<std::vector<int>> Imagen::getContenido()
{
  return contenido;
}
std::string Imagen::getPath() {
  return path;
}