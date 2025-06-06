#include <bits/stdc++.h>

#include "../core/Huffman/Huffman.h"
#include "../core/TADImagen.h"

Imagen *leerImagenHuff(std::string path) {
  std::ifstream archivo(path, std::ios::binary);

  if (!archivo.is_open())
    throw std::runtime_error("No se pudo acceder a " + path);

  unsigned short W, H;
  unsigned char M;
  std::vector<unsigned char> data;

  archivo.read(reinterpret_cast<char *>(&W), sizeof(W));
  archivo.read(reinterpret_cast<char *>(&H), sizeof(H));
  archivo.read(reinterpret_cast<char *>(&M), sizeof(M));

  std::vector<unsigned long> reps(((int)M) + 1, 0);

  unsigned long long repsSize =
      sizeof(unsigned long) * (((unsigned long long)M) + 1LL);

  archivo.read(reinterpret_cast<char *>(reps.data()), repsSize);

  while (!archivo.eof()) {
    unsigned char c;
    archivo.read(reinterpret_cast<char *>(&c), sizeof(unsigned char));
    data.push_back(c);
  }
  archivo.close();

  Huffman *h = new Huffman;
  h->loadTree(reps);

  std::vector<std::vector<int>> contenido = h->decode(W, H, data);

  Imagen *imagen = new Imagen(path, (int)W, (int)H, M, contenido);

  delete h;

  return imagen;
}