/**
 * @file TADVolumen.h
 * @brief Definición de la clase Volumen
 */

#ifndef TADVOLUMEN_H
#define TADVOLUMEN_H

#include <bits/stdc++.h>

#include "TADImagen.h"

/**
 * @class Volumen
 * @brief Clase que implementa el TAD Volumen.
 */

class Volumen
{
private:
  std::vector<Imagen> imagenes; ///< Conjunto de imagenes del volumen
  unsigned int n_im;            ///< Numero de imagenes en el volumen
  std::string baseName;         ///< Nombre base de las imagenes de volumen
  unsigned int height;          ///< Altura de las imagenes del volumen
  unsigned int width;           ///< Ancho de las imagenes del volumen

public:
  /**
   * @brief Constructor del volumen, revisa cada dato antes de crear un volumen
   * @param imagenes Conjunto de imagenes del volumen
   * @throw out_of_range si la cantidad de imagenes es invalida
   */
  Volumen(std::vector<Imagen> imagenes);

  /**
   * @brief Retorna el conjunto de imagenes del volumen
   * @return Imagenes del volumen
   */
  std::vector<Imagen> getImagenes();

  /**
   * @brief Retorna una imagen en la posicion solicitada del conjunto de imagenes
   * @return Imagen en la posicion del conjunto de imagenes
   * @throw runtime_error si el indice de la imagen no es valido o no representa ninguna imagen en el volumen
   */
  Imagen getImagen(unsigned int n_imagen);

  /**
   * @brief Retorna el numero de imagenes que contiene el volumen
   * @return Numero de imagenes del volumen
   */
  unsigned int getNumeroImagenes();

  /**
   * @brief Retorna el base name del volumen
   * @return baseName del volumen
   */
  std::string getBaseName();

  /**
   * @brief Retorna la altura de las imagenes
   * @return altura de las imagenes
   */
  unsigned short getAltura();

  /**
   * @brief Retorna el ancho de las imagenes
   * @return ancho de las imagenes
   */
  unsigned short getAncho();
};

#endif