/**
 * @file proyectarVolumen.h
 * @brief Definición de proyectarVolumen
 */

#ifndef PROYECTARVOLUMEN_H
#define PROYECTARVOLUMEN_H

#include <bits/stdc++.h>
#include "../core/TADImagen.h"
#include "../core/TADVolumen.h"

/**
 * @brief Dado un volumen, una dirección y un criterio, genera una proyección en la dirección especificada con el criterio especificado y guarda estos datos como una nueva imagen.
 * @return Imagen - Proyección 2D del volumen en la dirección especificada con el criterio especificado.
 * @param vol Volumen
 * @param direccion Caracter `x`, `y` o `z` que representa la dirección.
 * @param criterio Criterio de proyección, puede ser mediana, promedio, maximo o minimo.
 * @throw runtime_error si la direccion o criterio no son correctos.
 * 
 */
Imagen *proyectarVolumen(Volumen *vol, char direccion, std::string criterio);

#endif