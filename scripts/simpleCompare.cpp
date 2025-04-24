#include <bits/stdc++.h>

#define ll long long

using namespace std;

std::random_device rd;
std::mt19937 g(rd());

#define endl "\n"

class Imagen {
 public:
  ll ancho;            ///< Ancho de la imagen
  ll alto;             ///< Alto de la imagen
  int max_intensidad;  ///< Maxima intensidad de iluminación en la imagen
  std::vector<std::vector<int>> contenido;

  Imagen(ll ancho, ll alto, int max_intensidad,
         std::vector<std::vector<int>> contenido)
      : ancho(ancho),
        alto(alto),
        max_intensidad(max_intensidad),
        contenido(contenido) {}
};

Imagen* genImage(ll ancho, ll alto, int max_intensidad) {
  vector<vector<int>> contenido(alto, vector<int>(ancho, 0));

  uniform_int_distribution<> genV(0, max_intensidad);

  for (ll i = 0; i < alto; i++) {
    for (ll j = 0; j < ancho; j++) {
      contenido[i][j] = genV(g);
    }
  }

  return new Imagen(ancho, alto, max_intensidad, contenido);
}

std::string leerLineaArchivo(std::ifstream& archivo) {
  std::string linea;

  if (!std::getline(archivo, linea)) return "";

  int inicio = linea.find_first_not_of(" \t\r\n");
  if (inicio == std::string::npos) return "";

  int fin = linea.find_last_not_of(" \t\r\n");

  return linea.substr(inicio, fin - inicio + 1);
}

std::vector<int> getIntVectorFromStr(std::string linea) {
  char lin[linea.size() + 1];
  std::vector<int> nums;

  std::strcpy(lin, linea.c_str());

  char* token = std::strtok(lin, " ");

  while (token != NULL) {
    char* endptr;
    long num = std::strtol(token, &endptr, 10);

    if (*endptr == '\0') {
      nums.push_back((int)num);
      token = strtok(NULL, " ");
    } else {
      cout << ("El archivo no esta en el formato correcto");
    }
  }

  return nums;
}

Imagen* leerImagenPGM(std::string path) {
  std::ifstream archivo(path);

  if (!archivo.is_open()) cout << ("El archivo " + path + " no se pudo abrir");

  int step = 1;
  std::vector<int> contenido;

  try {
    while (!archivo.eof()) {
      std::string linea = leerLineaArchivo(archivo);

      if (linea[0] == '#') continue;

      switch (step) {
        case 1: {
          if (linea != "P2")
            cout
                << ("La imagen esta en un formato invalido, no comienza con "
                    "P2");
          step = 2;
          break;
        }

        case 2: {
          std::vector<int> nums = getIntVectorFromStr(linea);

          for (int i = 0; i < nums.size(); i++) contenido.push_back(nums[i]);
          break;
        }

        default:
          cout << ("Algo salio mal leyendo el archivo");
      }
    }
    archivo.close();
  } catch (const std::exception& err) {
    archivo.close();
    cout << (err.what());
  }

  if (contenido.size() < 3)
    cout
        << ("La imagen esta en un formato invalido, no contiene ancho alto ni "
            "intensidad maxima.");

  int W = contenido[0];
  int H = contenido[1];
  int M = contenido[2];

  if (H <= 0)
    cout << ("La imagen esta en un formato invalido, alto es negativo");
  if (W <= 0)
    cout << ("La imagen esta en un formato invalido, ancho es negativo");
  if (M < 0 || M > 255)
    cout
        << ("La imagen esta en un formato invalido, la intensidad maxima esta "
            "fuera del rango (0 - 255)");

  if (contenido.size() < (W * H) + 3) cout << ("El archivo esta incompleto");

  std::vector<std::vector<int>> mContenido(H, std::vector<int>(W, 0));

  for (int vi = 3; vi < contenido.size(); vi++) {
    int mi = vi - 3;

    if (mi >= (W * H)) break;

    int i = floor(mi / W);
    int j = mi % W;

    if (contenido[vi] < 0)
      cout << ("Se intento leer un pixel con intensidad negativa");

    int pixel = contenido[vi];

    if (pixel > M)
      cout
          << ("Se intento leer un pixel con intensidad mayor a la maxima "
              "especificada por el archivo.");

    mContenido[i][j] = pixel;
  }

  Imagen* imagen = new Imagen(W, H, M, mContenido);

  return imagen;
}

int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Uso incorrecto" << endl;
    cout << " + " << argv[0] << " <imagen 1> <imagen 2>" << endl;
    exit(1);
  }

  Imagen* img1 = leerImagenPGM(argv[1]);
  cout << "Imagen 1 cargada" << endl;
  Imagen* img2 = leerImagenPGM(argv[2]);
  cout << "Imagen 2 cargada" << endl;

  cout << "Comparando Imagenes" << endl;
  if (img1->alto == img2->alto && img1->ancho == img2->ancho &&
      img1->max_intensidad == img2->max_intensidad) {
    cout << "Alto, ancho e Intensidad revisados y correctos!" << endl;
  } else {
    cout << "Algo salio mal revisando alto, ancho e intensidad" << endl;
    exit(1);
  }

  if (img1->contenido.size() == img2->contenido.size() &&
      img1->contenido[0].size() == img2->contenido[0].size()) {
    cout << "Contenido del mismo tam" << endl;
  } else {
    cout << "Algo salio mal, contenido de tam diferente." << endl;
    exit(1);
  }

  cout << "Revisando matriz..." << endl;
  for (int i = 0; i < img1->alto; i++) {
    for (int j = 0; j < img1->ancho; j++) {
      if (img1->contenido[i][j] != img2->contenido[i][j]) {
        cout << "Error en (" << i << "," << j << ")" << endl;
        cout << "Valor = " << img2->contenido[i][j] << endl;
        exit(1);
      }
    }
  }

  cout << "Imagen Correcta" << endl;

  cout << "  Ancho = " << img1->ancho << endl;
  cout << "  Alto = " << img1->alto << endl;
  cout << "  MaxIntensidad = " << img1->max_intensidad << endl;
  cout << "  Pixeles = " << img1->ancho * img1->alto << endl;

  delete img1;
  delete img2;

  return 0;
}