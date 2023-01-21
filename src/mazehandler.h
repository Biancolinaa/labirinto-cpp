#ifndef MAZEHANDLER_H
#define MAZEHANDLER_H

#include <memory>
#include <string>

#include "lib/fromfile.h"
#include "lib/maze.h"

struct MazeFile {
  MazeMatrix maze;
  Coord start;
  Coord end;
};

class MazeHandler : public FromFile<MazeFile> {
private:
  std::unique_ptr<Maze> maze;
  MazeFile parse();

public:
  MazeHandler(std::string);
  void printSolution();
};

#endif