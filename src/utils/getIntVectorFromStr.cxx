/**
 * @file getIntVectorFromStr.cxx
 * @brief Implementacion de getIntVectorFromStr.h
 * @throw runtime_error si la linea no contiene solo numeros
 */

#include<bits/stdc++.h>

std::vector<int> getIntVectorFromStr(std::string linea) {

  char lin[linea.size() + 1];
  std::vector<int> nums;

  std::strcpy(lin, linea.c_str());

  char *token = std::strtok(lin, " ");

  while (token != NULL)
  {
    char *endptr;
    long num = std::strtol(token, &endptr, 10);

    if (*endptr == '\0')
    {
      nums.push_back((int) num);
      token = strtok(NULL, " ");
    }
    else
    {
      throw std::runtime_error("El archivo no esta en el formato correcto");
    }
  }

  return nums;
}