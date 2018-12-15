// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int c = matrix[0].size() - 1, r = 0;
  while (r < matrix.size() && c >= 0) {
    if (matrix[r][c] == target)
      return true;
    else if (matrix[r][c] > target)
      ++r;
    else
      --c;
  }
  return false;
}
