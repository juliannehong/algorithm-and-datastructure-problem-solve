// https://leetcode.com/problems/rotate-image/description/
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
  const int N = matrix.size();
  int rotationCount = N / 2, centerOfrotation = (N % 2 == 0) ? N/2 - 1 : N/2, rotateSize = (N % 2 == 0) ? 2 : 3;
  for (int i = 0; i < rotationCount; ++i){
    vector<int> temp(rotateSize);
    vector<int> up
  }
  
}
