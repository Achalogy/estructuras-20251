#include<bits/stdc++.h>

std::string leerLineaArchivo(std::ifstream &archivo)
{
  std::string linea;

  if (!std::getline(archivo, linea))
    return "";

  int inicio = linea.find_first_not_of(" \t\r\n");
  if (inicio == std::string::npos)
    return ""; 

  int fin = linea.find_last_not_of(" \t\r\n");

  return linea.substr(inicio, fin - inicio + 1);
}