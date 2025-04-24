#include <bits/stdc++.h>

#define ll long long

using namespace std;

#ifdef DEBUG
#define DEBUG_MSG(str)              \
  do {                              \
    cout << "\e[34m" << "[DEBUG] "; \
    cout << str << endl;            \
    cout << "\e[0m";                \
  } while (false)
#define DEBUG_EXEC(statement)              \
  do {                                     \
    cout << "\e[34m" << "[DEBUG]" << endl; \
    statement;                             \
    cout << "\e[0m";                       \
  } while (false)
#else
#define DEBUG_MSG(str) ((void)0)
#define DEBUG_EXEC(str) ((void)0)
#endif

std::random_device rd;
std::mt19937 g(rd());

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
  if (argc != 4) {
    cout << "Uso incorrecto" << endl;
    cout << " + " << argv[0] << " <ejecutable> <n imagenes> <maxImageSize>"
         << endl;
    exit(1);
  }

  string executablePath = argv[1];
  char* token = NULL;
  ll nImages = strtoll(argv[2], &token, 10);

  if (*token != '\0') {
    cout << "Uso incorrecto" << endl;
    cout << " + " << argv[0] << " <ejecutable> <n imagenes> <maxImageSize>"
         << endl;
    exit(1);
  }

  ll maxImageSize = strtoll(argv[3], &token, 10);
  if (*token != '\0') {
    cout << "Uso incorrecto" << endl;
    cout << " + " << argv[0] << " <ejecutable> <n imagenes> <maxImageSize>"
         << endl;
    exit(1);
  }

  const string sScript = executablePath + " > /dev/null 2>&1 << 'EOF'\n" +
                         "cargar_imagen in.pgm\n"
                         "codificar_imagen coded.huf\n"
                         "decodificar_archivo coded.huf out.pgm\n"
                         "salir\n" +
                         "EOF";

  const char* script = sScript.c_str();

  DEBUG_MSG("Comenzando a generar " << nImages << " imagenes");

  for (int i = 0; i < nImages; i++) {
    uniform_int_distribution<> genDimension(
        (maxImageSize / 100) > 0 ? maxImageSize / 100 : 1, maxImageSize);
    uniform_int_distribution<> genIntensidad(1, 255);

    ll ancho, alto;
    int intensidad = genIntensidad(g);

    ancho = genDimension(g);
    alto = genDimension(g);

    cout << "Imagen " << i + 1 << " " << ancho << "x" << alto << " ("
         << intensidad << ") pixeles = " << ancho * alto << " ";

    DEBUG_EXEC(cout << "Generando imagen " << i + 1 << endl;
               cout << "  Ancho = " << ancho << endl;
               cout << "  Alto = " << alto << endl;
               cout << "  MaxIntensidad = " << intensidad << endl;
               cout << "  Pixeles = " << ancho * alto << endl;);

    Imagen* img = genImage(ancho, alto, intensidad);

    DEBUG_MSG("Imagen generada");

    std::ofstream archivo("in.pgm");

    if (!archivo.is_open()) {
      cout << endl;
      cout << ("No se pudo acceder a in.out");
      exit(1);
    }

    std::vector<std::vector<int>>& contenido = img->contenido;

    archivo << "P2" << std::endl;
    archivo << ancho << " " << alto << std::endl;
    archivo << img->max_intensidad << std::endl;

    for (int i = 0; i < alto; i++) {
      for (int j = 0; j < ancho; j++) {
        int value = contenido[i][j];

        archivo << value;

        if (j != ancho - 1) archivo << " ";
      }

      if (i != alto - 1) archivo << std::endl;
    }

    archivo.close();

    DEBUG_MSG("Se genero el archivo in.pgm");
    DEBUG_MSG("Ejecutando proyecto");

    system(script);

    Imagen* outImg = leerImagenPGM("out.pgm");
    DEBUG_MSG("Archivo pgm decodificado leido");

    // Comparar imagenes

    DEBUG_MSG("Comparando Imagenes");
    if (img->alto == outImg->alto && img->ancho == outImg->ancho &&
        img->max_intensidad == outImg->max_intensidad) {
      DEBUG_MSG("Alto, ancho e Intensidad revisados y correctos!");
    } else {
      cout << endl;
      cout << "Algo salio mal revisando alto, ancho e intensidad" << endl;
      exit(1);
    }

    if (img->contenido.size() == outImg->contenido.size() &&
        img->contenido[0].size() == outImg->contenido[0].size()) {
      DEBUG_MSG("Contenido del mismo tam");
    } else {
      cout << endl;
      cout << "Algo salio mal, contenido de tam diferente." << endl;
      exit(1);
    }

    DEBUG_MSG("Revisando matriz...");
    for (int i = 0; i < img->alto; i++) {
      for (int j = 0; j < img->ancho; j++) {
        if (img->contenido[i][j] != outImg->contenido[i][j]) {
          cout << endl;
          cout << "Error en (" << i << "," << j << ")" << endl;
          cout << "Valor = " << outImg->contenido[i][j] << endl;
          exit(1);
        }
      }
    }

    delete img;
    delete outImg;

    cout << "Correcta" << endl;

    DEBUG_EXEC(system("ls -lh | grep in.pgm");
               system("ls -lh | grep coded.huf");
               system("ls -lh | grep out.pgm"););
  }

  cout << "CORRECTO!" << endl;
}
