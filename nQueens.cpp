#include <vector>
#include <iostream>
using namespace std;


bool isValid(int i, int j, const vector<vector<int>>& board){
  // vertial check
  for (int r = 0; r < i; ++r){
    if (r != i && board[r][j] == 1)
      return false;
  }
  // no need to check horizontal; computing row by row
  for (int r = 0; r < i; ++r){
    if (i-r >= 0 && j-r >= 0){
      if (board[i-r][j-r] == 1)
        return false;
    }
    if (i-r >= 0 && j+r < board.size()){
      if (board[i-r][j+r] == 1)
        return false;
    }
  }
  return true;
}

bool helper(int n, int currentRowIndex, vector<vector<int>>& board) {
  if (n == currentRowIndex)
    return true;
  for (int j = 0; j < n; ++j){
    if (isValid(currentRowIndex, j, board)) {
      board[currentRowIndex][j] = 1;
      if (helper(n, currentRowIndex + 1, board))
        return true;
      else
        board[currentRowIndex][j] = 0;
    }
  }
  return false;
}

vector<vector<int>> nQueensOneSolution(int n){
  vector<vector<int>> board(n, vector<int>(n, 0));
  if (helper(n, 0, board))
      return board;
  else
      return {};
}


int main(){
  vector<vector<int>> re = nQueensOneSolution(4);
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j){
      cout << re[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
