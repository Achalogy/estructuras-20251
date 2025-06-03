#ifndef TADNODO_H
#define TADNODO_H

struct TADNodo {
 protected:
  unsigned int x;
  unsigned int y;

 public:
  TADNodo(unsigned int x, unsigned int y);

  unsigned int getX();
  unsigned int getY();
  void setX(unsigned int _x);
  void setY(unsigned int _y);
};

#endif