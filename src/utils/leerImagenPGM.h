/**
 * @file leerImagenPGM.h
 * @brief Definición de leerImagenPGM
 */

#ifndef LEERIMAGENPGM_H
#define LEERIMAGENPGM_H

#include <bits/stdc++.h>
#include "../core/TADImagen.h"

/**
 * @brief Lee la imagen de un path especificado
 * @return Apuntador a la imagen leida
 * @throw runtime_error si hay algun error a la hora de leer la imagen o no sigue el formato esperado
 * @param path Ubicación de la imagen a leer
 */
Imagen *leerImagenPGM(std::string path);

#endif