/**
 * @file TADSistema.cxx
 * @brief Implementaciones de TADSistema.h
 */

#include <bits/stdc++.h>

#include "TADSistema.h"

std::vector<std::string> Sistema::getNextLine()
{
  return cm.getNextLine();
}

int Sistema::ejecutarComando(std::vector<std::string> argv)
{
  return cm.ejecutarComando(argv, memoria);
}