/**
 * @file Sistema.cxx
 * @brief Implementación del TAD sistema Sistema.h
 */

#include <bits/stdc++.h>

#include "Sistema.h"

Sistema::Sistema() {
  imagenEnMemoria = nullptr;
};

std::vector<std::string> Sistema::getNextLine()
{
  return cm.getNextLine();
}

int Sistema::ejecutarComando(std::vector<std::string> argv)
{
  return cm.ejecutarComando(argv);
}