#include "maze.h"

#include "square.h"

using namespace std;

Maze::Maze(MazeMatrix maze, Coord start, Coord end)
{
  this->maze = maze;
  this->start = start;
  this->end = end;
}

Maze::~Maze() {}

Coord Maze::startPosition() { return start; }
Coord Maze::endPosition() { return end; }

CoordList Maze::solve()
{
  vector<Coord>().swap(solution);
  for (int i = 0; i < maze.size(); i++)
  {
    for (int j = 0; j < maze[i].size(); j++)
    {
      if (maze[i][j].status() == Visited)
        maze[i][j].setStatus(Free);
    }
  }

  if (solve(start))
  {
    return solution;
  }
  else
  {
    return vector<Coord>();
  }
}

bool Maze::solve(Coord coord)
{
  solution.push_back(coord);

  maze[coord.x][coord.y].setStatus(Visited);

  if (coord.x == end.x && coord.y == end.y)
  {
    return true;
  }

  Coord c;

  // Check up
  c.x = coord.x - 1;
  c.y = coord.y;
  if (isFree(c) && solve(c))
  {
    return true;
  }

  // Check down
  c.x = coord.x + 1;
  c.y = coord.y;
  if (isFree(c) && solve(c))
  {
    return true;
  }

  // Check left
  c.x = coord.x;
  c.y = coord.y - 1;
  if (isFree(c) && solve(c))
  {
    return true;
  }

  // Check right
  c.x = coord.x;
  c.y = coord.y + 1;
  if (isFree(c) && solve(c))
  {
    return true;
  }

  solution.pop_back();
  maze[coord.x][coord.y] = Free;
  return false;
}

bool Maze::isFree(Coord c)
{
  return isSafe(c) && maze[c.x][c.y].status() == Free;
}

bool Maze::isSafe(Coord c)
{
  return c.x >= 0 && c.x < maze.size() && c.y >= 0 && c.y < maze[0].size();
}

string Maze::prettify()
{
  string output = "╔";
  for (int i = 0; i < maze[0].size(); i++)
    output.append("══");
  output.append("╗\n");

  for (int i = 0; i < maze.size(); i++)
  {
    output.append("║");
    for (int j = 0; j < maze[i].size(); j++)
    {
      output.append(maze[i][j].prettify());
    }
    output.append("║\n");
  }

  output.append("╚");
  for (int i = 0; i < maze[0].size(); i++)
    output.append("══");
  output.append("╝\n");

  return output;
}