#include "TADNodo.h"

#include <bits/stdc++.h>

using namespace std;

TADNodo::TADNodo(unsigned int x, unsigned int y) : x(x), y(y) {}

unsigned int TADNodo::getX() {
  return x;
}

unsigned int TADNodo::getY() {
  return y;
}

void TADNodo::setX(unsigned int _x) {
  x = _x;
}

void TADNodo::setY(unsigned int _y) {
  y = _y;
}