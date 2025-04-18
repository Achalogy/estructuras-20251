#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <bits/stdc++.h>

#include "ArbolHuffman.h"

class Huffman {
 protected:
  ArbolHuffman *arbol;
  std::vector<unsigned long> reps;

 public:
  Huffman();
  ~Huffman();

  /**
   * @brief Recibe una matriz 2d de enteros y genera el arbol de huffman en base
   * a esta, cada entero representa un pixel.
   */
  void genTree(std::vector<std::vector<int>> contenido);
  /**
   * @brief Recibe un vector de elementos. Por cada elemento e_i:
   *
   * i es cada valor de luminosidad del pixel
   * e_i es la cantidad de veces que aparece esta luminosidad
   */
  void loadTree(std::vector<unsigned long> r_reps);

  /**
   * @brief Retorna una matriz de enteros, cada entero es un pixel de la imagen
   */
  std::vector<std::vector<int>> decode(int W, int H,
                                       std::vector<unsigned char> &data);

  /**
   * @brief Retorna un vector de unsigned char, esta es la imagen codificada.
   *
   * Tener cuidado, cada unsigned char del vector NO representa un pixel!
   * Para obtener el pixel se debe decodificar
   */
  std::vector<unsigned char> encode(std::vector<std::vector<int>> content);

  void writeGraph();

  std::vector<unsigned long> getReps();
};

#endif