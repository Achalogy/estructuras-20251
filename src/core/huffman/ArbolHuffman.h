#ifndef ARBOLHUFFMAN_H
#define ARBOLHUFFMAN_H

#include <bits/stdc++.h>
#include "NodoHuffman.h"
#include "DatoHuffman.h"

class ArbolHuffman
{
protected:
  NodoHuffman *raiz;
  std::map<int, std::string> codes;

public:
  ~ArbolHuffman();
  ArbolHuffman(NodoHuffman *nodo);

  void actualizarTabla();
  void actualizarTabla(std::string path, NodoHuffman *nodo);
  std::map<int, std::string> &obtenerTabla();
  void writeGraph();
  NodoHuffman *obtenerRaiz();
};

#endif