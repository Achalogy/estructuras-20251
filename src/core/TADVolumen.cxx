/**
 * @file TADImagen.cxx
 * @brief Implementaciones de TADImagen.h
 */

 #include <bits/stdc++.h>

 #include "TADVolumen.h"
 #include "TADImagen.cxx"
 
 Volumen::Volumen(unsigned int r_n_im, std::vector<Imagen> r_imagenes)
 {
   // Verificar valores
   if (n_im > 99 || n_im < 0)
     throw std::out_of_range("Dimensiones invalidas");
   if (imagenes.size > 99 || imagenes.size < 0)
     throw std::out_of_range("Dimension de las imagenes invalidas, debe estar entre 0 y 99 (inclusivo)");
 
   // Datos verificados
 
   this->n_im = r_n_im;
   this->imagenes = r_imagenes;
 }
 
 vector<Imagen> Volumen::getImagenes()
 {
   return this->imagenes;
 }
 Imagen Volumen::getImagen(unsigned int n_imagen)
 {
    if (n_imagen < imagenes.size)
      return this->imagenes[n_imagen];
 }
 unsigned int Volumen::getNumeroImagenes()
 {
   return this->n_im;
 }
 