#ifndef DATOHUFFMAN_H
#define DATOHUFFMAN_H

#include <bits/stdc++.h>

class DatoHuffman {
 public:
  int c;
  unsigned long n;
  DatoHuffman(int c, unsigned long n);
  DatoHuffman();

  friend std::ostream &operator<<(std::ostream &os, const DatoHuffman &p) {
    if (p.c == -1) {
      os << "(" << p.c << "," << p.n << ")";
    } else {
      os << "(" << p.c << "," << p.n << ")";
    }
    return os;
  }
};

#endif