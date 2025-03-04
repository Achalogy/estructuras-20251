#include <bits/stdc++.h>

#include "../core/TADImagen.h"
#include "leerLineaArchivo.h"
#include "getIntVectorFromStr.h"

Imagen *leerImagenPGM(std::string path)
{
  std::ifstream archivo(path);

  if (!archivo.is_open())
    throw std::runtime_error("El archivo " + path + " no se pudo abrir");

  int step = 1;
  std::vector<int> contenido;

  while (!archivo.eof())
  {
    std::string linea = leerLineaArchivo(archivo);

    if (linea[0] == '#')
      continue;

    switch (step)
    {
    case 1:
    {
      if (linea != "P2")
        throw std::runtime_error("La imagen esta en un formato invalido, no comienza con P2");
      step = 2;
      break;
    }

    case 2:
    {
      std::vector<int> nums = getIntVectorFromStr(linea);

      for (int i = 0; i < nums.size(); i++)
        contenido.push_back(nums[i]);
      break;
    }

    default:
      throw std::runtime_error("Algo salio mal leyendo el archivo");
    }
  }

  if (contenido.size() < 3)
    throw std::runtime_error("La imagen esta en un formato invalido, no contiene ancho alto ni intensidad maxima.");

  int W = contenido[0];
  int H = contenido[1];
  int M = contenido[2];

  if (W <= 0 || H <= 0 || M < 0 || M > 255)
    throw std::runtime_error("La imagen esta en un formato invalido");

  if (contenido.size() < (W * H) + 3)
    throw std::runtime_error("El achivo esta incompleto");

  std::vector<std::vector<unsigned short>> mContenido(H, std::vector<unsigned short>(W, 0));

  for (int vi = 3; vi < contenido.size(); vi++)
  {
    int mi = vi - 3;

    int i = floor(mi / W);
    int j = mi % W;

    if (contenido[mi] < 0)
      throw std::runtime_error("Se intento leer un pixel con intensidad negativa");

    unsigned short pixel = (unsigned short)contenido[mi];

    if (pixel > M)
      throw std::runtime_error("Se intento leer un pixel con intensidad mayor a la maxima especificada por el archivo.");

    mContenido[i][j] = pixel;
  }

  Imagen *imagen = new Imagen((unsigned int)W, (unsigned int)H, (unsigned short)M, mContenido);

  return imagen;
}