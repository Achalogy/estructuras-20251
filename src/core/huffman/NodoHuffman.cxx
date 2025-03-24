#ifndef NODOHUFFMAN_CXX
#define NODOHUFFMAN_CXX

#include <bits/stdc++.h>
#include "NodoHuffman.h"

NodoHuffman::NodoHuffman()
{
  hijoDer = NULL;
  hijoIzq = NULL;
}

DatoHuffman &NodoHuffman::obtenerDato()
{
  return dato;
}

void NodoHuffman::fijarDato(DatoHuffman &val)
{
  dato = val;
}

NodoHuffman *NodoHuffman::obtenerHijoDer()
{
  return hijoDer;
}

NodoHuffman *NodoHuffman::obtenerHijoIzq()
{
  return hijoIzq;
}

void NodoHuffman::fijarHijoIzq(NodoHuffman *izq)
{
  hijoIzq = izq;
}

void NodoHuffman::fijarHijoDer(NodoHuffman *der)
{
  hijoDer = der;
}

#endif