#ifndef DATOHUFFMAN_H
#define DATOHUFFMAN_H

#include <bits/stdc++.h>

class DatoHuffman
{
public:
  int c;
  int n;
  DatoHuffman(int c, int n);
  DatoHuffman();

  friend std::ostream &operator<<(std::ostream &os, const DatoHuffman &p)
  {
    if (p.c == -1)
    {
      os << "(" << p.c << "," << p.n << ")";
    }
    else
    {
      os << "(" << p.c << "," << p.n << ")";
    }
    return os;
  }
};

#endif