/**
 * @file getIntVectorFromStr.h
 * @brief Definición de getIntVectorFromStr
 */

#ifndef GETINTVECTORFROMSTR_H
#define GETINTVECTORFROMSTR_H

#include<bits/stdc++.h>

/**
 * @brief Procesa una linea para convertirla a un vector de números
 * @param linea Linea leia desde un archivo
 * @throw runtime_error si la linea contiene caracteres diferentes a números
 * @return std::vector<int> Arreglo de números procesado de la linea
 */
std::vector<int> getIntVectorFromStr(std::string linea);

#endif