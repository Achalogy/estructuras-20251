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
  int n_im;            ///< Numero de imagenes en el volumen
  std::string baseName;         ///< Nombre base de las imagenes del volumen
  int altura;          ///< Altura de las imagenes del volumen
  int ancho;           ///< Ancho de las imagenes del volumen

public:
  /**
   * @brief Constructor del volumen, revisa cada dato antes de crear un volumen
   * @param r_imagenes Conjunto de imagenes del volumen
   * @param r_baseName Nombre base de las imagenes del volumen
   * @throw out_of_range si la cantidad de imagenes es invalida
   */
  Volumen(std::string r_baseName, std::vector<Imagen> r_imagenes);

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
  Imagen getImagen(int n_imagen);

  /**
   * @brief Retorna el numero de imagenes que contiene el volumen
   * @return Numero de imagenes del volumen
   */
  int getNumeroImagenes();

  /**
   * @brief Retorna el base name del volumen
   * @return baseName del volumen
   */
  std::string getBaseName();

  /**
   * @brief Retorna la altura de las imagenes
   * @return altura de las imagenes
   */
  int getAltura();

  /**
   * @brief Retorna el ancho de las imagenes
   * @return ancho de las imagenes
   */
  int getAncho();
};

#endif