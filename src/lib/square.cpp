#include "square.h"

using namespace std;

Square::Square(SquareStatus status) { this->setStatus(status); }

Square::~Square() {}

SquareStatus Square::status() { return this->stat; }

void Square::setStatus(SquareStatus status) { this->stat = status; }

std::string Square::prettify() {
  switch (this->stat) {
  case Free:
    return "  ";
  case Visited:
    return "░░";
  case Wall:
    return "██";
  }
}

void Square::fromString(string s) {
  if (s == ".")
    this->stat = Free;
  else
    this->stat = Wall;
}

void Square::fromChar(char c) {
  string s(1, c);
  this->fromString(s);
}
