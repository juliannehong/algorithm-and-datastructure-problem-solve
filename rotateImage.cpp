// https://leetcode.com/problems/rotate-image/description/
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
const int layerCount = matrix.size() / 2;
int wallIndex = matrix.size() - 1; 
for (int i = 0; i < layerCount; ++i){
  for (int j = i; j < wallIndex - i; ++j){  
      int temp1 = matrix[wallIndex - j][i]; // lower right corner   
      int temp2 = matrix[wallIndex - i][wallIndex - j]; // lower right corner
      int temp3 = matrix[j][wallIndex - i]; // upper right corner (only move verticle; j should be row)
      int temp4 = matrix[i][j]; // upper left corner
      
      matrix[i][j] = temp1;
      matrix[wallIndex - j][i] = temp2;
      matrix[wallIndex - i][wallIndex - j] = temp3;
      matrix[j][wallIndex - i] = temp4;
    }
  } 
}