// cstyle array and string
#include <iostream>
using namespace std;

int* reverseArrayCopy(int* arr, int n) {
  int* result = new int[n]{};
  for (int i = 0; i < n; ++i) {
    result[i] = arr[n-1-i];
  }
  return result;
}

int** matrixFunc(int** matrix, int R, int C) {
  int count = 1;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      matrix[i][j] = count++;
    }
  }
  return matrix;
}

int main() {
  
  int* arr_heap = new int[5]{1,2,3,4,5};
  int arr_stack[5] = {1,2,3,4,5};
  
  int** matrix_heap = new int*[3]{};
  for (int i = 0; i < 3; ++i) {
    matrix_heap[i] = new int[4]{};
  }
  
  matrix_heap = matrixFunc(matrix_heap, 3, 3);
  
  int matrix_stack[3][3] = {{3,2,1},{2,4,5},{4,2,1}};
  
  //matrix_stack = matrixFunc(matrix_stack, 3, 3); -> won't work!
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << matrix_stack[i][j] << " ";
    }
    cout << endl;
  }
//  arr_stack[4] = 6;
//  arr_heap[4] = 6;

//  int* result = reverseArrayCopy(arr_heap, 5);
//  int* result2 = reverseArrayCopy(arr_stack, 5);
//  for (int i = 0; i < 5; ++i) {
//    cout << result2[i];
//  }
  

  
  

  return 0;
}
