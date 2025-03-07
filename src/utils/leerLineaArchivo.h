/**
 * @file leerLineaArchivo.h
 * @brief Definición de leerLineaArchivo
 */

#ifndef LEERLINEAARCHIVO_H
#define LEERLINEAARCHIVO_H

#include<bits/stdc++.h>

/**
 * @brief Lee una linea de un archivo y elimina los espacios extra al inicio y al final
 * @return std::string contiene la linea leida
 * @param archivo objeto std::ifstream valido del archivo a leer una linea
 */
std::string leerLineaArchivo(std::ifstream &archivo);

#endif