/**
 * @file TADMemoria.cxx
 * @brief Implementaciones de TADMemoria.h
 */

#include <bits/stdc++.h>

#include "TADMemoria.h"

Memoria::Memoria() : imagenEnMemoria(nullptr), volumenEnMemoria(nullptr) {}

Imagen *Memoria::getImagenEnMemoria()
{
  return imagenEnMemoria;
}

void Memoria::setImagenEnMemoria(Imagen *r_imagen) {

  if(imagenEnMemoria != nullptr)
    delete imagenEnMemoria; // Liberar memoria

  imagenEnMemoria = r_imagen;
}

Volumen *Memoria::getVolumenEnMemoria() {
  return volumenEnMemoria;
}

void Memoria::setVolumenEnMemoria(Volumen *r_volumen) {
  
  if(volumenEnMemoria != nullptr)
    delete volumenEnMemoria; // Liberar memoria

  volumenEnMemoria = r_volumen;
}