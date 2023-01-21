#include <iostream>

#include "mazehandler.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: maze [FILENAME]\n");
    return 1;
  }

  auto filename = argv[1];

  auto mh = new MazeHandler(filename);
  mh->printSolution();
  delete mh;
  return 0;
}