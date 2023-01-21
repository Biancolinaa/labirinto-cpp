#include "coord.h"

#include <sstream>

using namespace std;

void Coord::fromString(string s) {
  istringstream ssin(s);
  ssin >> this->x >> this->y;
}

string Coord::prettify() {
  ostringstream ssout;
  ssout << "(" << this->x << ", " << this->y << ")";
  return ssout.str();
}