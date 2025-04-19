#ifndef HUFFMAN_CXX
#define HUFFMAN_CXX

#include "Huffman.h"

#include <bits/stdc++.h>

Huffman::Huffman() { arbol = NULL; }

Huffman::~Huffman() {
  if (arbol != NULL) {
    delete arbol;
    arbol = NULL;
  }
  reps.clear();
}

void Huffman::genTree(std::vector<std::vector<int>> contenido) {
  reps = std::vector<unsigned long>(256, 0);

  for (std::vector<int> f : contenido)
    for (int i : f) reps[i]++;

  loadTree(reps);
}

void Huffman::loadTree(std::vector<unsigned long> r_reps) {
  std::priority_queue<NodoHuffman *, std::vector<NodoHuffman *>,
                      ComparadorNodoHuffman>
      q;

  for (int i = 0; i < r_reps.size(); i++) {
    if (r_reps[i] != 0) {
      NodoHuffman *n = new NodoHuffman();
      DatoHuffman val(i, r_reps[i]);
      n->fijarDato(val);
      q.push(n);
    }
  }

  while (q.size() >= 2) {
    NodoHuffman *n1 = q.top();
    q.pop();
    NodoHuffman *n2 = q.top();
    q.pop();

    DatoHuffman &d1 = n1->obtenerDato();
    DatoHuffman &d2 = n2->obtenerDato();

    NodoHuffman *nNodo = new NodoHuffman();

    DatoHuffman val(-1, d1.n + d2.n);
    nNodo->fijarDato(val);

    nNodo->fijarHijoIzq(n1);
    nNodo->fijarHijoDer(n2);

    q.push(nNodo);
  }

  arbol = new ArbolHuffman(q.top());
  q.pop();

  arbol->actualizarTabla();
}

std::vector<unsigned char> Huffman::encode(
    std::vector<std::vector<int>> content) {
  std::vector<unsigned char> bytes;

  unsigned char buffer = 0;
  int bit_pos = 0;

  for (std::vector<int> f : content)
    for (int i : f) {
      std::string path = arbol->obtenerTabla()[i];

      for (char c : path) {
        bool bit = c == '1';

        buffer = (buffer << 1) | bit;
        bit_pos++;

        if (bit_pos == 8) {
          bytes.push_back(buffer);
          buffer = 0;
          bit_pos = 0;
        }
      }
    }

  return bytes;
}

std::vector<unsigned long> Huffman::getReps() { return reps; }

void Huffman::writeGraph() { arbol->writeGraph(); }

std::queue<bool> *getRaw(std::vector<unsigned char> data) {
  std::queue<bool> *q = new std::queue<bool>;

  for (unsigned char c : data) {
    q->push((c >> 7) & 1 == 1);
    q->push((c >> 6) & 1 == 1);
    q->push((c >> 5) & 1 == 1);
    q->push((c >> 4) & 1 == 1);
    q->push((c >> 3) & 1 == 1);
    q->push((c >> 2) & 1 == 1);
    q->push((c >> 1) & 1 == 1);
    q->push((c >> 0) & 1 == 1);
  }

  return q;
}

int leerPixelData(NodoHuffman *raiz, std::queue<bool> *q) {
  NodoHuffman *n = raiz;

  while (n->obtenerDato().c == -1) {
    n = q->front() ? n->obtenerHijoDer() : n->obtenerHijoIzq();
    q->pop();
  }

  return n->obtenerDato().c;
}

std::vector<std::vector<int>> Huffman::decode(
    int W, int H, std::vector<unsigned char> &data) {
  std::vector<std::vector<int>> contenido(H, std::vector<int>(W, 0));
  int bit_pos = 8;
  int i_byte = -1;
  unsigned char buffer;
  NodoHuffman *raiz = arbol->obtenerRaiz();

  std::queue<bool> *q = getRaw(data);

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      contenido[i][j] = leerPixelData(raiz, q);
    }
  }

  delete q;

  return contenido;
}

#endif