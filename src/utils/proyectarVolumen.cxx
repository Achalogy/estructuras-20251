#include <bits/stdc++.h>

#include "../core/TADImagen.h"
#include "../core/TADVolumen.h"
#include "proyectarVolumen.h"

std::vector<int> lanzarRayo(Volumen *vol, std::vector<int> mov, int x, int y, int z)
{
  std::vector<int> nums;
  std::vector<Imagen> imagenes = vol->getImagenes();

  while (true)
  {
    if (x < 0 || x >= vol->getAncho() ||
        y < 0 || y >= vol->getAltura() ||
        z < 0 || z >= vol->getNumeroImagenes())
      break;

    nums.push_back(
        imagenes[z].getContenido()[y][x]);

    x += mov[0];
    y += mov[1];
    z += mov[2];
  }

  return nums;
}

int calcularPixel(std::vector<int> rayo, char criterio)
{
  int v = 0;

  switch (criterio)
  {
  case 'p': // promedio
  {
    for (int i : rayo)
      v += i;
    v /= rayo.size();
    break;
  }
  case 'n': // mediana
  {
    if (rayo.size() == 1)
      return rayo[0];
    sort(rayo.begin(), rayo.end());
    int mid = rayo.size() / 2;

    if (rayo.size() % 2 == 0)
    {
      v = rayo[mid - 1] + rayo[mid];
      v /= 2;
    }
    else
    {
      v = rayo[mid];
    }
    break;
  }
  case 'm': // minimo
  {
    v = INT_MAX;
    for (int i : rayo)
      if (i < v)
        v = i;
    break;
  }
  case 'M': // maximo
  {
    for (int i : rayo)
      if (i > v)
        v = i;
    break;
  }

  default:
    throw std::runtime_error("Criterio Invalido");
  }

  return v;
}

Imagen *proyectarVolumen(Volumen *vol, char direccion, char criterio)
{
  std::vector<std::vector<int>> proyeccion;

  int H, W;

  // [x, y, z]
  // x - mov columna en imagen
  // y - mov fila en imagen
  // z - cambio de imagen
  std::vector<int> mov(3, 0);

  switch (direccion)
  {
  case 'x':
  {
    H = vol->getNumeroImagenes();
    W = vol->getAncho();

    // proj = [x, y, z] = [j, 1, n - i - 1]
    mov[1] = 1;

    break;
  }
  case 'y':
  {
    H = vol->getAltura();
    W = vol->getNumeroImagenes();

    // proj = [x, y, z] = [1, i, n - j - 1]
    mov[0] = 1;

    break;
  }
  case 'z':
  {
    H = vol->getAltura();
    W = vol->getAncho();

    // proj = [x, y, z] = [j, i, 1]
    mov[2] = 1;

    break;
  }

  default:
    throw std::runtime_error("Direccion Invalida");
  }

  proyeccion = std::vector<std::vector<int>>(H, std::vector<int>(W, -1));

  int M = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      std::vector<int> rayo;

      if (direccion == 'x')
        rayo = lanzarRayo(vol, mov, j, 0, vol->getNumeroImagenes() - i - 1);
      if (direccion == 'y')
        rayo = lanzarRayo(vol, mov, 0, i, vol->getNumeroImagenes() - j - 1);
      if (direccion == 'z')
        rayo = lanzarRayo(vol, mov, j, i, 0);

      proyeccion[i][j] = calcularPixel(rayo, criterio);

      if (proyeccion[i][j] > M)
        M = proyeccion[i][j];
    }
  }

  return new Imagen("", W, H, M, proyeccion);
}
