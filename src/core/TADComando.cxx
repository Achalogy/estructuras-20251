#include<bits/stdc++.h>

#include "TADComando.h"
#include "TADImagen.h"

Comando::Comando(std::string n, int nA, std::function<int(std::vector<std::string>, Memoria memoria)> f)
{
  this->name = n;
  this->minArgs = nA;
  this->function = f;
}