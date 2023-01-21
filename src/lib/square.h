#ifndef SQUARE_H
#define SQUARE_H

#include <string>

#include "fromstring.h"
#include "pretty.h"

enum SquareStatus { Free, Visited, Wall };

class Square : public Pretty, public FromString {
private:
  SquareStatus stat;

public:
  Square(SquareStatus);
  virtual ~Square();

  std::string prettify();

  SquareStatus status();
  void setStatus(SquareStatus);

  void fromString(std::string);
  void fromChar(char);
};

#endif