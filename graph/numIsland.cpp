#include <iostream>
#include <vector>
using namespace std;

bool isValid(const vector<vector<char>>& grid, int r, int c){
  return r < grid.size() && c < grid[0].size() && r >= 0 && c >= 0;
}

void DFS(vector<vector<char>>& grid, int r, int c) {
  grid[r][c] = '0';
  const vector<vector<int>> shifts {{-1, 0},{1, 0}, {0, -1}, {0, 1}};
  for (auto shift : shifts) {
    int newR = r + shift[0], newC = c + shift[1];
    if (isValid(grid, newR, newC) && grid[newR][newC] == '1')
      DFS(grid, r + shift[0], c + shift[1]);
  }
}

int numIslands(vector<vector<char>>& grid) {
  int count = 0;
  for (int i = 0; i < grid.size(); ++i){
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == '1') {
        DFS(grid, i, j);
        count++;
      }
    }
  }
  return count;
}

int main() {
  vector<vector<char>> grid1 {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}};
  cout << numIslands(grid1) << endl;
  return 0;
}
