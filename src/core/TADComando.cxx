/**
 * @file TADComando.cxx
 * @brief Implementaciones de TADComando.h
 */

#include<bits/stdc++.h>

#include "TADComando.h"
#include "TADImagen.h"

Comando::Comando(std::string n, int nA, std::function<int(std::vector<std::string>, Memoria &memoria)> f)
{
  name = n;
  minArgs = nA;
  function = f;
}