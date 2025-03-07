/**
 * @file TADComando.h
 * @brief Guarda el nombre del comando, la cantidad minima de argumentos y su función
 */

#include "TADMemoria.h"

#ifndef TADCOMANDO_H
#define TADCOMANDO_H

#include <bits/stdc++.h>

/**
 * @class Comando
 * @brief Representa un comando con su nombre, número mínimo de argumentos y su función asociada.
 */

class Comando
{
public:
  std::string name;                                                       ///< Nombre del comando
  int minArgs;                                                            ///< Número mínimo de argumentos requeridos
  std::function<int(std::vector<std::string>, Memoria &memoria)> function; ///< Función que ejecuta el comando

public:
  /**
   * @brief Constructor parametrizado.
   * @param n Nombre del comando
   * @param nA Número mínimo de argumentos
   * @param f Función asociada al comando
   */
  Comando(std::string n, int nA, std::function<int(std::vector<std::string>, Memoria &memoria)> f);
};

#endif