#ifndef NODOHUFFMAN_CXX
#define NODOHUFFMAN_CXX

#include "NodoHuffman.h"

#include <bits/stdc++.h>

NodoHuffman::NodoHuffman() {
  hijoDer = NULL;
  hijoIzq = NULL;
}

NodoHuffman::~NodoHuffman() {
  if (hijoDer != NULL) delete hijoDer;
  if (hijoIzq != NULL) delete hijoIzq;
  hijoDer = NULL;
  hijoIzq = NULL;
}

DatoHuffman &NodoHuffman::obtenerDato() { return dato; }

void NodoHuffman::fijarDato(DatoHuffman &val) { dato = val; }

NodoHuffman *NodoHuffman::obtenerHijoDer() { return hijoDer; }

NodoHuffman *NodoHuffman::obtenerHijoIzq() { return hijoIzq; }

void NodoHuffman::fijarHijoIzq(NodoHuffman *izq) { hijoIzq = izq; }

void NodoHuffman::fijarHijoDer(NodoHuffman *der) { hijoDer = der; }

#endif