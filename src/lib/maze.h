#ifndef MAZE_H
#define MAZE_H

#include <vector>

#include "coord.h"
#include "pretty.h"
#include "square.h"

typedef std::vector<std::vector<Square>> MazeMatrix;
typedef std::vector<Coord> CoordList;

class Maze : public Pretty {
private:
  Coord start;
  Coord end;
  CoordList solution;
  MazeMatrix maze;
  bool solve(Coord);
  bool isFree(Coord);
  bool isSafe(Coord);

public:
  Maze(MazeMatrix, Coord, Coord);
  virtual ~Maze();

  Coord startPosition();
  Coord endPosition();
  CoordList solve();
  std::string prettify();
};

#endif