#include <bits/stdc++.h>

#include "./core/TADSistema.h"
#include "./utils/leerVolumen.h"
#include "./utils/leerImagenPGM.h"
#include "./utils/proyectarVolumen.h"

bool validateDirection()
{
}

void executeTest(std::string path, int n_im)
{
  Volumen *inVol = leerVolumen(path, n_im);
  Imagen *outImg;

  Imagen *gen;

  if (outImg->getAlto() != gen->getAlto() || outImg->getAncho() != gen->getAlto())
    throw std::runtime_error("Dimensiones incorrectas");

  std::vector<std::pair<int, int>> errors;

  for (int i = 0; i < outImg->getAlto(); i++)
  {
    for (int j = 0; j < outImg->getAncho(); j++)
    {
      if (outImg->getContenido()[i][j] !=
          gen->getContenido()[i][j])
        errors.push_back(std::make_pair(i, j));
    }
  }

  if (errors.size() > 0)
  {
    std::string errorString = "Valor incorrecto en: \n";
    for (auto i : errors)
      errorString += "  [" + std::to_string(i.first) + "," + std::to_string(i.second) + "]\n";

    throw std::runtime_error(errorString);
  }
}

void mostrarImg(Imagen *img)
{
  for (std::vector<unsigned short> v : img->getContenido())
  {
    for (unsigned short i : v)
    {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  Sistema sys;
  std::cout << "Sistema de test Proyeccion 2D" << std::endl;

  int testCount = 1;

  try
  {
    std::cout << "Ejecutando test 1" << std::endl;
    executeTest("src/tests/proyeccion2D/data/vol1/img", 2);
    std::cout << "O Test 1 Correcto" << std::endl;
    testCount++;
  }
  catch (const std::exception &err)
  {
    std::cerr << "Error: " << err.what();
  }

  // std::vector<std::string> cmd;

  // cmd.push_back("cargar_volumen");
  // cmd.push_back("src/tests/proyeccion2D/data/vol1/img");
  // cmd.push_back("2");

  // int execCode = sys.ejecutarComando(cmd);

  // std::cout << "Código ejecutado con " << execCode << std::endl;

  // try
  // {
  //   Volumen *vol = leerVolumen("src/tests/proyeccion2D/data/vol1/img", 2);
  //   Imagen *img;

  //   std::cout << "Revisando x:" << std::endl;
  //   img = proyectarVolumen(vol, 'x', 'M');
  //   mostrarImg(img);
  //   std::cout << "Revisando y:" << std::endl;
  //   img = proyectarVolumen(vol, 'y', 'M');
  //   mostrarImg(img);
  //   std::cout << "Revisando z:" << std::endl;
  //   img = proyectarVolumen(vol, 'z', 'M');
  //   mostrarImg(img);
  // }
  // catch (const std::exception &err)
  // {
  //   std::cerr << err.what();
  // }

  return 0;
}