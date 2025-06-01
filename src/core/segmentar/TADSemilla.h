#ifndef TADSEMILLA_H
#define TADSEMILLA_H

#include <bits/stdc++.h>

using namespace std;

class Semilla {
 protected:
  unsigned char tag;
  unsigned int x;
  unsigned int y;

 public:
  Semilla(unsigned char tag, unsigned int x, unsigned int y);

  unsigned char getTag();
  unsigned int getX();
  unsigned int getY();
  void setTag(unsigned char r_tag);
  void setX(unsigned int r_x);
  void setY(unsigned int r_y);
};

#endif