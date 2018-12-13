#include <vector>
#include <iostream>
using namespace std;

bool isValid(int N, int r, int c, const vector<vector<int>>& board){
  if (r < 0 || c < 0 || r >= N || c >= N)
    return false;
  for (int i = 0; i < N; ++i){
    if (board[i][c] == 1)
      return false;
    if (r + i < N && c + i < N)
      if (board[r + i][c + i] == 1)
        return false;
    if (r - i >= 0 && c - i >= 0)
      if (board[r - i][c - i] == 1)
        return false;
  }
  return true;
}

bool nQueens(const int N, int r, vector<vector<int>>& board){
  if (r == N)
    return true;
  for (int i = 0; i < N; ++i){
    if (isValid(N, r, i, board)) {
      board[r][i] = 1;
      if (nQueens(N, r + 1, board))
        return true;
      else
        board[r][i] = 0;
    }
  }
  return false;
}

vector<vector<int>> nQueens(int N) {
  vector<vector<int>> board(N, vector<int>(N, 0));
  if (nQueens(N, 0, board))
    return board;
  else
    return {};
}

int main() {
  auto board = nQueens(5);
  for (int i = 0; i < 5; ++i){
    for (int j = 0; j < 5; ++j) {
      cout << board[i][j];
    }
    cout << endl;
  }
  return 0;
}
