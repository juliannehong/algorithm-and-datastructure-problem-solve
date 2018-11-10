// https://leetcode.com/problems/gray-code/description/ NOT DONE
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

bool helper(const int n, int currentIndex, vector<int>& codes, vector<bool>& counted) {
  cout << pow(2,n) << endl;
  if (pow(2,n) == currentIndex)
    return true;
  int prev = codes[currentIndex-1];
  cout << prev <<endl;
  for (int i = 0; i < n; ++i){
    int newNum = (prev % int(pow(2,i)) == 1) ? prev - int(pow(2,i)) : prev + int(pow(2,i));
    if (!counted[newNum]){
      codes.push_back(newNum);
      counted[newNum] = true;
      if (helper(n, currentIndex + 1, codes, counted))
        return true;
      else {
        codes.pop_back();
        counted[newNum] = false;
      }
    }
  }
  return false;
}

vector<int> grayCode(int n) {
  vector<int> codes;
  const int totalCount = pow(n,2);
  vector<bool> counted(totalCount, false);
  codes.push_back(0);
  counted[0] = true;
  helper(n, 1, codes, counted);
  return codes;
}
