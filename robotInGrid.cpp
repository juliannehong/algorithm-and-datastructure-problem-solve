// Cracking coding interview 6ed 8.2
#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

struct Coordinate{
  int r;
  int c;
  bool operator=(const& rhs) const {return r == rhs.r && c == rhs.c;}
}

bool findPath(const vector<vector<bool>>& maze, int r, int c, list<Coordinate>& thePath, unordered_set<Coordinate>& failedCoordinates) {
  // base case
  if (r < 0 || c < 0 || !maze[r][c])
    return false;
  if (failedCoordinates.find({r, c}) != failedCoordinates.end())
    return false;
  if (r == 0 && c == 0) // origin
    return true;
  if (findPath(maze, r-1, c, thePath, failedCoordinates) || findPath(maze, r, c-1, thePath, failedCoordinates)) {
    thePath.push_back({r,c});
    return true;
  }
  failedCoordinates.insert({r, c});
  return false;
}

list<Coordinate> findPath(const vector<vector<bool>>& maze) {
  list<Coordinate> thePath;
  unordered_set<Coordinate> failedCoordinates;
  if (findPath(maze, maze.size()-1, maze[0].size()-1, thePath, failedCoordinates))
    return findPath;
  else
    return {};
}


