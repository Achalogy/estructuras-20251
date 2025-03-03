#include<bits/stdc++.h>

#include "TADComando.h"
#include "TADImagen.h"

Comando::Comando(std::string n, int nA, std::function<int(std::vector<std::string>, Imagen * imagenEnMemoria)> f)
{
  this->name = n;
  this->minArgs = nA;
  this->function = f;
}