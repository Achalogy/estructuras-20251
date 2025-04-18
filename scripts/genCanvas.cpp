#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    cout << "Uso correcto: " << endl;
    cout << argv[0] << " <nombre de archivo> <tamY> <tamX>" << endl;
    exit(1);
  }

  ll tamY = 0;
  ll tamX = 0;

  char *ptr;
  tamY = strtol(argv[2], &ptr, 10);
  if (*ptr != '\0')
  {
    cout << "TamY no es un numero valido" << endl;
    cout << "Uso correcto: " << endl;
    cout << argv[0] << " <nombre de archivo> <tamY> <tamX>" << endl;
    exit(1);
  }
  tamX = strtol(argv[3], &ptr, 10);
  if (*ptr != '\0')
  {
    cout << "TamX no es un numero valido" << endl;
    cout << "Uso correcto: " << endl;
    cout << argv[0] << " <nombre de archivo> <tamY> <tamX>" << endl;
    exit(1);
  }

  ofstream salida(argv[1]);

  if(!salida.is_open())
  {
    cout << "El archivo " << argv[1] << " no se puede escribir" << endl;
    cout << "Uso correcto: " << endl;
    cout << argv[0] << " <nombre de archivo> <tamY> <tamX>" << endl;
    exit(1);
  }

  salida << "P2" << endl;
  salida << tamY << " " << tamX << endl;
  salida << 255 << endl;
  for(int i = 0; i < tamY; i++){
    for(int j = 0; j < tamX; j++){
      salida << 255;
      if(j != tamX -1) salida << " ";
    }
    if(i != tamY-1) salida << endl;
  }

  cout << "Archivo " << argv[1] << " escrito con exito" << endl;
}