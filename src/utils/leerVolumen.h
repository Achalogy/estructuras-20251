/**
 * @file leerVolumen.h
 * @brief Definición de leerVolumen
 */

#ifndef LEERVOLUMENPGM_H
#define LEERVOLUMENPGM_H

#include <bits/stdc++.h>
#include "../core/TADVolumen.h"
#include "leerImagenPGM.h"

/**
 * @brief Lee el volumen con un `baseName` especificado y una cantidad de imagenes `n_im`
 * @return Apuntador al volumen
 * @throw runtime_error si hay algun error a la hora de cargar el volumen o no sigue el formato 
 * @param baseName Nombre base del volumen
 * @param n_im cantidad de imagenes a leer
 */
Volumen *leerVolumen(std::string baseName, int n_im);

#endif