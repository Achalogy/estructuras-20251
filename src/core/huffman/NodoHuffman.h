#ifndef NODOHUFFMAN_H
#define NODOHUFFMAN_H

#include "DatoHuffman.h"

class NodoHuffman {
 protected:
  DatoHuffman dato;
  NodoHuffman *hijoIzq;
  NodoHuffman *hijoDer;

 public:
  NodoHuffman();
  ~NodoHuffman();
  DatoHuffman &obtenerDato();
  void fijarDato(DatoHuffman &val);
  NodoHuffman *obtenerHijoIzq();
  NodoHuffman *obtenerHijoDer();
  void fijarHijoIzq(NodoHuffman *izq);
  void fijarHijoDer(NodoHuffman *der);
};

struct ComparadorNodoHuffman {
  bool operator()(NodoHuffman *a, NodoHuffman *b) {
    return a->obtenerDato().n > b->obtenerDato().n;
  }
};

#endif