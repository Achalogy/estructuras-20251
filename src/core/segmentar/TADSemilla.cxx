#ifndef TADSEMILLA_CXX
#define TADSEMILLA_CXX

#include "TADSemilla.h"

#include <bits/stdc++.h>

using namespace std;

Semilla::Semilla(unsigned char tag, unsigned int x, unsigned int y)
    : tag(tag), x(x), y(y) {}

unsigned char Semilla::getTag() { return tag; }
unsigned int Semilla::getX() { return x; }
unsigned int Semilla::getY() { return y; }
void Semilla::setTag(unsigned char r_tag) { tag = r_tag; };
void Semilla::setX(unsigned int r_x) { x = r_x; };
void Semilla::setY(unsigned int r_y) { y = r_y; };

#endif