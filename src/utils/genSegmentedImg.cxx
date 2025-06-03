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

struct CompareWeights {
  bool operator()(const dijNode &a, const dijNode &b) const {
    return a.first > b.first;
  }
};

void processNeighborPixel(
    Imagen *img,  // Imagen original
    dijNode a,    // Pixel actual
    priority_queue<dijNode, vector<dijNode>, CompareWeights>
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
    distances[y][x] = distances[a.second.getY()][a.second.getX()] + w;
    q.push(make_pair(distances[y][x], TADNodo(x, y)));
  }
}

Imagen *genSegmentedImg(Imagen *img, vector<Semilla> semillas) {
  vector<vector<ul>> finalDistances(img->getAlto(),
                                    vector<ul>(img->getAncho(), ULONG_MAX));
  vector<vector<int>> contenido(img->getAlto(),
                                vector<int>(img->getAncho(), 0));

  priority_queue<dijNode, vector<dijNode>, CompareWeights> q;

  int maxIntensidad = 0;

  for (Semilla s : semillas) {
    // Por cada semilla son independientes estas variables, para comparar las
    // distancias tenemos el vector de distancias finales

    maxIntensidad = max(maxIntensidad, (int)s.getTag());

    vector<vector<ul>> distances(img->getAlto(),
                                 vector<ul>(img->getAncho(), ULONG_MAX));
    vector<vector<bool>> visited(img->getAlto(),
                                 vector<bool>(img->getAncho(), false));

    // Poner la semilla, su distancia a si misma es 0
    distances[s.getY()][s.getX()] = 0;
    // Por la misma razón, este pixel siempre es de esta semilla
    contenido[s.getY()][s.getX()] = s.getTag();

    q.push(make_pair(0, TADNodo(s.getX(), s.getY())));

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
  }

  return new Imagen(img->getPath(), img->getAncho(), img->getAlto(),
                    maxIntensidad, contenido);
}

#endif