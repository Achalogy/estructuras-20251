#ifndef ARBOLHUFFMAN_CXX
#define ARBOLHUFFMAN_CXX

#include "ArbolHuffman.h"

#include <bits/stdc++.h>

ArbolHuffman::ArbolHuffman(NodoHuffman *nodo) { raiz = nodo; }

ArbolHuffman::~ArbolHuffman() {
  if (raiz != NULL) {
    delete raiz;
    raiz = NULL;
  }
  codes.clear();
}

void ArbolHuffman::actualizarTabla() {
  codes = std::map<int, std::string>();

  actualizarTabla("", raiz);
}

void ArbolHuffman::actualizarTabla(std::string path, NodoHuffman *nodo) {
  if (nodo->obtenerHijoDer() == NULL && nodo->obtenerHijoIzq() == NULL) {
    codes[nodo->obtenerDato().c] = path;
    return;
  } else {
    if (nodo->obtenerHijoIzq() != NULL) {
      actualizarTabla(path + "0", nodo->obtenerHijoIzq());
    }
    if (nodo->obtenerHijoDer() != NULL) {
      actualizarTabla(path + "1", nodo->obtenerHijoDer());
    }
  }
}

std::map<int, std::string> &ArbolHuffman::obtenerTabla() { return codes; }

std::string getStrPointer(NodoHuffman *ptr) {
  std::stringstream ss;
  ss << ptr;
  std::string str = "\"" + ss.str() + "\"";
  return str;
}

void ArbolHuffman::writeGraph() {
  if (raiz == NULL) return;

  std::ofstream file("arbol.dot");

  if (!file.is_open()) {
    std::cerr << "No se pudo escribir el archivo" << std::endl;
    return;
  }

  file << "digraph G {" << std::endl;

  std::queue<NodoHuffman *> q;
  std::string relations = "";

  q.push(raiz);

  int n = 1;

  while (!q.empty()) {
    while (n--) {
      NodoHuffman *nodo = q.front();
      q.pop();

      std::string strpointer = getStrPointer(nodo);

      file << strpointer << " [label = \"" << nodo->obtenerDato() << "\"];\n";

      if (nodo->obtenerHijoIzq() != NULL) {
        q.push(nodo->obtenerHijoIzq());
        std::string strCpointer = getStrPointer(nodo->obtenerHijoIzq());
        relations += strpointer + " -> " + strCpointer + ";\n";
      }
      if (nodo->obtenerHijoDer() != NULL) {
        q.push(nodo->obtenerHijoDer());
        std::string strCpointer = getStrPointer(nodo->obtenerHijoDer());
        relations += strpointer + " -> " + strCpointer + ";\n";
      }
    }
    n = q.size();
  }

  file << "\n" << relations << "}";
  file.close();
}

NodoHuffman *ArbolHuffman::obtenerRaiz() { return raiz; }

#endif