#include "mazehandler.h"

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

MazeHandler::MazeHandler(string filename) : FromFile<MazeFile>(filename) {
  auto mf = parse();
  this->maze.reset(new Maze(mf.maze, mf.start, mf.end));
}

void MazeHandler::printSolution() {
  auto m = maze.get();
  Coord start = m->startPosition();
  Coord end = m->endPosition();
  printf("Starting from %s\n", start.prettify().c_str());
  printf("Exit is at    %s\n", end.prettify().c_str());
  printf("Maze is\n%s\n", m->prettify().c_str());

  CoordList sol = m->solve();
  if (sol.size() == 0) {
    printf("No solution found\n");
    return;
  }

  printf("Solution found\n%s\n", m->prettify().c_str());
}

MazeFile MazeHandler::parse() {
  ifstream fin(FromFile::filename);
  MazeMatrix maze;
  MazeFile mf;

  string line;
  getline(fin, line);
  mf.start.fromString(line);

  getline(fin, line);
  mf.end.fromString(line);

  while (getline(fin, line)) {
    if (line.size() == 0)
      continue;

    vector<Square> row;
    for (char c : line) {
      Square sq(Wall);
      sq.fromChar(c);
      row.push_back(sq);
    }
    mf.maze.push_back(row);
  }

  fin.close();
  return mf;
}
