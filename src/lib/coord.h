#ifndef COORD_H
#define COORD_H

#include <string>

#include "fromstring.h"
#include "pretty.h"

class Coord : public FromString, public Pretty {
public:
  int x;
  int y;

  Coord() : x(0), y(0) {}
  Coord(int x, int y) : x(x), y(y) {}
  virtual ~Coord() {}

  void fromString(std::string);
  std::string prettify();
};

#endif