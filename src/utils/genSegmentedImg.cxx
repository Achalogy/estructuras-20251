#ifndef GENSEGMENTEDIMG_CXX
#define GENSEGMENTEDIMG_CXX

#include <bits/stdc++.h>

#include "../core/TADImagen.h"
#include "../core/segmentar/TADNodo.h"
#include "../core/segmentar/TADSemilla.h"
#include "../lib/colors.h"
#include "../lib/debug.h"

using namespace std;

#define ul unsigned long

#define dijNode pair<ul, TADNodo>

void processNeighborPixel(
    Imagen *img,  // Imagen original
    dijNode a,    // Pixel actual
    priority_queue<dijNode, vector<dijNode>, greater<dijNode>>
        &q,                         // Cola de prioridad Dijkstra
    vector<vector<ul>> &distances,  // Distancias de la semilla actual

    // Usados para simplificar la lógica, por ejemplo, pasando i = 0, j = 1
    // significaría que estamos revisando el pixel derecho y i = 1, j = 0 el
    // pixel de abajo
    int i, int j) {
  int y = a.second.getY() + i;
  int x = a.second.getX() + j;

  if (y < 0 || y >= distances.size()) return;
  if (x < 0 || x >= distances[0].size()) return;

  // Calcular el peso de la arista
  ul w = abs(img->getContenido()[a.second.getY()][a.second.getX()] -
             img->getContenido()[y][x]);

  if (distances[a.second.getY()][a.second.getX()] + w < distances[y][x]) {
    distances[y][x] = distances[a.second.getY()][a.second.getY()] + w;
    q.push(make_pair(distances[y][x], TADNodo(y, x)));
  }
}

Imagen *genSegmentedImg(Imagen *img, vector<Semilla> semillas) {
  vector<vector<ul>> finalDistances(img->getAlto(),
                                    vector<ul>(img->getAncho(), ULONG_MAX));
  vector<vector<int>> contenido(img->getAlto(),
                                vector<int>(img->getAncho(), 0));

  priority_queue<dijNode, vector<dijNode>, greater<dijNode>> q;

  map<int, string> colors;
  string sColors[5] = {__COLOR_RED, __COLOR_GREEN, __COLOR_YELLOW, __COLOR_CYAN,
                       __COLOR_MAGENTA};
  for (int i = 0; i < semillas.size(); i++) {
    colors[semillas[i].getTag()] = sColors[i];
  }

  for (Semilla s : semillas) {
    // Por cada semilla son independientes estas variables, para comparar las
    // distancias tenemos el vector de distancias finales

    vector<vector<ul>> distances(img->getAlto(),
                                 vector<ul>(img->getAncho(), ULONG_MAX));
    vector<vector<bool>> visited(img->getAlto(),
                                 vector<bool>(img->getAncho(), false));

    // Poner la semilla, su distancia a si misma es 0
    distances[s.getY()][s.getX()] = 0;
    // Por la misma razón, este pixel siempre es de esta semilla
    contenido[s.getY()][s.getX()] = s.getTag();

    q.push(make_pair(0, TADNodo(s.getY(), s.getX())));

    while (!q.empty()) {
      dijNode a = q.top();
      q.pop();

      unsigned int x = a.second.getX();
      unsigned int y = a.second.getY();

      if (visited[y][x]) continue;

      visited[y][x] = true;

      if (distances[y][x] < finalDistances[y][x]) {
        contenido[y][x] = s.getTag();

        finalDistances[y][x] = distances[y][x];
      }

      // Procesar los pixeles que comparten un lado
      processNeighborPixel(img, a, q, distances, -1, 0);
      processNeighborPixel(img, a, q, distances, 0, 1);
      processNeighborPixel(img, a, q, distances, 1, 0);
      processNeighborPixel(img, a, q, distances, 0, -1);
    }

    DEBUG_EXEC(for (auto l : contenido) {
      for (int pixel : l) {
        cout << colors[pixel];
        cout << setfill('0') << setw(3) << pixel << " ";
        cout << __COLOR_BLUE;
      }
      cout << endl;
    });

    DEBUG_EXEC(for (auto l : distances) {
      for (int d : l) {
        cout << d << " ";
      }
      cout << endl;
    });
  }

  return new Imagen(img->getPath(), img->getAncho(), img->getAlto(),
                    img->getMaxIntensidad(), contenido);
}

#endif