#include <bits/stdc++.h>

#include "../core/Huffman/Huffman.h"
#include "../core/TADImagen.h"

void guardarImagenHUFF(Imagen *img, std::vector<unsigned long> reps,
                       std::vector<unsigned char> data, std::string path) {
  std::ofstream archivo(path, std::ios::binary);

  unsigned short W = img->getAncho();
  unsigned short H = img->getAlto();
  unsigned char M = img->getMaxIntensidad();

  if (!archivo.is_open())
    throw std::runtime_error("No se pudo acceder a " + path);

  archivo.write(reinterpret_cast<char *>(&W), sizeof(W));
  archivo.write(reinterpret_cast<char *>(&H), sizeof(H));
  archivo.write(reinterpret_cast<char *>(&M), sizeof(M));

  archivo.write(reinterpret_cast<char *>(reps.data()),
                reps.size() * sizeof(unsigned long));
  archivo.write(reinterpret_cast<char *>(data.data()), data.size());

  archivo.close();
}