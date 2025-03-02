/**
 * @file TADVolumen.h
 * @brief Definición de la clase 
 */

 #ifndef TADVOLUMEN_H
 #define TADVOLUMEN_H
 
 #include <bits/stdc++.h>

 #include "TADVolumen.h"
 
 /**
  * @class Volumen
  * @brief Clase que implementa el TAD Volumen.
  */
 
 class Volumen
 {
 private:
   std::Vector<Imagen> imagenes;          ///< Conjunto de imagenes del volumen

   unsigned int n_im;           ///< Numero de imagenes en el volumen
 
   // Contenido de la volumen
 
 public:
   /**
   * @brief Constructor del volumen, revisa cada dato antes de crear un volumen
   * @param imagenes Conjunto de imagenes del volumen
   * @param n_im Numero de imagenes en el volumen
   */
   Volumen(std::Vector<Imagen> imagenes, unsigned int n_im;);
 
   /**
    * @brief Retorna el conjunto de imagenes del volumen
    * @return imagenes del volumen
    */
   vector<Imagen> getImagenes()

   /**
    * @brief Retorna una imagen en la posicion solicitada del conjunto de imagenes
    * @return Imagen en la posicion del conjunto de imagenes
    */
   Imagen getImagen(unsigned int n_imagen)
 
   /**
    * @brief Retorna el numero de imagenes que contiene el volumen
    * @return numero de imagenes del volumen
    */
   unsigned int getNumeroImagenes()

   
 };
 
 #endif