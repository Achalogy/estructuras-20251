/**
 * @file leerImagenPGM.cxx
 * @brief Implementación de leerImagenPGM.h
 */

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

  try
  {
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
    archivo.close();
  }
  catch (const std::exception &err)
  {
    archivo.close();
    throw std::runtime_error(err.what());
  }

  if (contenido.size() < 3)
    throw std::runtime_error("La imagen esta en un formato invalido, no contiene ancho alto ni intensidad maxima.");

  int W = contenido[0];
  int H = contenido[1];
  int M = contenido[2];

  if (H <= 0)
    throw std::runtime_error("La imagen esta en un formato invalido, alto es negativo");
  if (W <= 0)
    throw std::runtime_error("La imagen esta en un formato invalido, ancho es negativo");
  if (M < 0 || M > 255)
    throw std::runtime_error("La imagen esta en un formato invalido, la intensidad maxima esta fuera del rango (0 - 255)");

  if (contenido.size() < (W * H) + 3)
    throw std::runtime_error("El archivo esta incompleto");

  std::vector<std::vector<int>> mContenido(H, std::vector<int>(W, 0));

  for (int vi = 3; vi < contenido.size(); vi++)
  {
    int mi = vi - 3;

    if (mi >= (W * H))
      break;

    int i = floor(mi / W);
    int j = mi % W;

    if (contenido[vi] < 0)
      throw std::runtime_error("Se intento leer un pixel con intensidad negativa");

    int pixel = contenido[vi];

    if (pixel > M)
      throw std::runtime_error("Se intento leer un pixel con intensidad mayor a la maxima especificada por el archivo.");

    mContenido[i][j] = pixel;
  }

  Imagen *imagen = new Imagen(path, W, H, M, mContenido);

  return imagen;
}