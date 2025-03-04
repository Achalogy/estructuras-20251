#ifndef TADMEMORIA_H
#define TADMEMORIA_H

/**
 * @file TADMemoria.h
 * @brief Archivo de definición del TAD Memoria
 */

#include "TADImagen.h"

/**
 * @class Memoria
 * @brief Contiene la memoria del programa, en esta se cargan las imagenes y volumenes
 */

class Memoria
{
private:
  Imagen *imagenEnMemoria; ///< Apuntador a la imagen en memoria

public:
  /**
   * @brief Devuelve la imagen guardada en memoria
   * @return Apuntador a la Imagen guardada en memoria
   */
  Imagen *getImagenEnMemoria();

  /**
   * @brief Actualiza la imagen guardada en memoria
   * @param imagen Apuntador de la imagen
   */
  void setImagenEnMemoria(Imagen *r_imagen);
};

#endif