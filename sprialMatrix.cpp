// https://leetcode.com/problems/spiral-matrix/description/
#include <vector>
using namespace std;

bool isValid(int x, int y, vector<vector<int>>& matrix) {
    return (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() && matrix[x][y] != 0);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  if (matrix.size() == 0)
    return {};
  vector<int> result;
  const vector<vector<int>> shifts{{0,1},{1,0},{0,-1},{-1,0}};
  int x = 0, y = 0, direction = 0;
  for (int i = 0; i < (matrix.size() * matrix[0].size()); ++i) {
    result.push_back(matrix[x][y]);
    matrix[x][y] = 0;
    int nextX = x + shifts[direction][0], nextY = y + shifts[direction][1];
    if (isValid(nextX, nextY, matrix)) {
      x = nextX;
      y = nextY;
    } else {
      direction = (direction + 1) % 4;
      x = x + shifts[direction][0];
      y = y + shifts[direction][1];
    }
  }
  return result;
}