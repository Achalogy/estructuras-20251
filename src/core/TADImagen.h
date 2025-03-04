/**
 * @file TADImagen.h
 * @brief Definición de la clase Imagen
 */
#include <bits/stdc++.h>

#ifndef TADIMAGEN_H
#define TADIMAGEN_H

/**
 * @class Imagen
 * @brief Clase que implementa el TAD Imagen.
 */

class Imagen
{
private:
  unsigned int ancho;            ///< Ancho de la imagen
  unsigned int alto;             ///< Alto de la imagen
  unsigned short max_intensidad; ///< Maxima intensidad de iluminación en la imagen
  std::string path;              ///< Ubicación de la imagen cargada

  // Contenido de la imagen
  std::vector<std::vector<unsigned short>> contenido; ///< Matriz 2D que contiene la imagen, cada valor esta entre 0 y 255, representa que tan iluminado esta el pixel

public:
  /**
   * @brief Constructor de la imagen, revisa cada dato antes de crear una imagen
   * @param r_ancho Ancho de la imagen
   * @param r_alto Alto de la imagen
   * @param r_max_intensidad Maxima intesidad de iluminación en la imagen
   * @param r_contenido Matriz 2D que contiene la imagen, cada valor esta entre 0 y 255, representa que tan iluminado esta el pixel
   */
  Imagen(std::string r_path, unsigned int r_ancho, unsigned int r_alto, unsigned short r_max_intensidad, std::vector<std::vector<unsigned short>> r_contenido);

  /**
   * @brief Retorna el path de la imagen
   * @return Path de la imagen
   */
  std::string getPath();

  /**
   * @brief Retorna el ancho de la imagen
   * @return Ancho de la imagen
   */
  unsigned int getAncho();

  /**
   * @brief Retorna el alto de la imagen
   * @return Alto de la imagen
   */
  unsigned int getAlto();

  /**
   * @brief Retorna la intensidad maxima de la imagen
   * @return Intensidad maxima de la imagen
   */
  unsigned short getMaxIntensidad();

  /**
   * @brief Retorna el contenido de la imagen
   * @return Contenido de la imagen
   */
  std::vector<std::vector<unsigned short>> getContenido();
};

#endif