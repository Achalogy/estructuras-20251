#include<bits/stdc++.h>

#include "TADComando.h"

Comando::Comando(std::string n, int nA, std::function<int(std::vector<std::string>)> f)
{
  this->name = n;
  this->minArgs = nA;
  this->function = f;
}