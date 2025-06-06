#ifndef TADMEMORIA_H
#define TADMEMORIA_H

/**
 * @file TADMemoria.h
 * @brief Archivo de definición del TAD Memoria
 */

#include "TADImagen.h"
#include "TADVolumen.h"

/**
 * @class Memoria
 * @brief Contiene la memoria del programa, en esta se cargan las imagenes y volumenes
 */

class Memoria
{
private:
  Imagen *imagenEnMemoria;   ///< Apuntador a la imagen en memoria
  Volumen *volumenEnMemoria; ///< Apuntador al volumen en memoria

public:

  /**
   * @brief Constructor de memoria, establece la imagen y el volumen como nullptr
   */
  Memoria();

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

  /**
   * @brief Devuelve el volumen guardado en memoria
   * @return Apuntador al volumen guardado en memoria
   */
  Volumen *getVolumenEnMemoria();

  /**
   * @brief Actualiza el volumen guardado en memoria
   * @param Volumen Apuntador del volumen
   */
  void setVolumenEnMemoria(Volumen *r_volumen);
};

#endif