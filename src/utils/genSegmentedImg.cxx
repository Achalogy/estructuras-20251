#ifndef GENSEGMENTEDIMG_CXX
#define GENSEGMENTEDIMG_CXX

#include <bits/stdc++.h>

#include "../core/TADImagen.h"
#include "../core/segmentar/TADSemilla.h"
#include "../lib/colors.h"
#include "../lib/debug.h"

using namespace std;

#define ul unsigned long

#define tup tuple<ul, pair<unsigned int, unsigned int>, unsigned char>

void followDij(Imagen *img, tup a,
               priority_queue<tup, vector<tup>, greater<tup>> &q,
               vector<vector<ul>> &distances, int i, int j) {
  int y = get<1>(a).first + i;
  int x = get<1>(a).second + j;

  if (y < 0 || y >= distances.size()) return;
  if (x < 0 || x >= distances[0].size()) return;

  ul w = abs(img->getContenido()[get<1>(a).first][get<1>(a).second] -
             img->getContenido()[y][x]);

  if (distances[get<1>(a).first][get<1>(a).second] + w < distances[y][x]) {
    distances[y][x] = distances[get<1>(a).first][get<1>(a).second] + w;
    q.push(make_tuple(distances[y][x], make_pair(y, x), get<2>(a)));
  }
}

Imagen *genSegmentedImg(Imagen *img, vector<Semilla> semillas) {
  vector<vector<int>> contenido(img->getAlto(),
                                vector<int>(img->getAncho(), 0));
  vector<vector<ul>> distances(img->getAlto(),
                               vector<ul>(img->getAncho(), ULONG_MAX));
  vector<vector<ul>> finalDistances(img->getAlto(),
                                    vector<ul>(img->getAncho(), ULONG_MAX));
  vector<vector<bool>> visited(img->getAlto(),
                               vector<bool>(img->getAncho(), false));

  priority_queue<tup, vector<tup>, greater<tup>> q;

  map<int, string> colors;
  string sColors[5] = {__COLOR_RED, __COLOR_GREEN, __COLOR_YELLOW, __COLOR_CYAN,
                       __COLOR_MAGENTA};
  for (int i = 0; i < semillas.size(); i++) {
    colors[semillas[i].getTag()] = sColors[i];
  }

  for (Semilla s : semillas) {
    distances = vector<vector<ul>>(img->getAlto(),
                                   vector<ul>(img->getAncho(), ULONG_MAX));
    visited = vector<vector<bool>>(img->getAlto(),
                                   vector<bool>(img->getAncho(), false));
    distances[s.getY()][s.getX()] = 0;
    contenido[s.getY()][s.getX()] = s.getTag();

    q.push(make_tuple(0, make_pair(s.getY(), s.getX()), s.getTag()));

    while (!q.empty()) {
      tup a = q.top();
      q.pop();

      if (visited[get<1>(a).first][get<1>(a).second]) continue;

      visited[get<1>(a).first][get<1>(a).second] = true;

      if (distances[get<1>(a).first][get<1>(a).second] <
          finalDistances[get<1>(a).first][get<1>(a).second]) {
        contenido[get<1>(a).first][get<1>(a).second] = get<2>(a);
        finalDistances[get<1>(a).first][get<1>(a).second] =
            distances[get<1>(a).first][get<1>(a).second];
      }

      followDij(img, a, q, distances, -1, 0);
      followDij(img, a, q, distances, 0, 1);
      followDij(img, a, q, distances, 1, 0);
      followDij(img, a, q, distances, 0, -1);
    }

    DEBUG_EXEC(for (auto l : contenido) {
      for (int pixel : l) {
        cout << colors[pixel];
        cout << setfill('0') << setw(3) << pixel << " ";
        cout << __COLOR_BLUE;
      }
      cout << endl;
    });
  }

  return new Imagen(img->getPath(), img->getAncho(), img->getAlto(),
                    img->getMaxIntensidad(), contenido);
}

#endif