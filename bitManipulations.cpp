#include <iostream>
using namespace std;

bool isPowerOfTwo(int x) {
  while (x % 2 == 0) x /= 2;
  return x == 1;
}

int countOneBits(int x) {
  int result = 0;
  int n = 1;
  while (n <= x) {
    if ((n & x) == n)
      result++;
    n <<= 1;
  }
  return result;
}

bool isKthSet(int n, int k) {
  int m = 1 << (k - 1);
  return (n & m) == m;
}

vector<string> generateAllBitPatterns(int n) {
  
}

int main(){
  /*--- built-in ---*/
  cout << bitset<5>(3) << endl; // 00011
  cout << bitset<4>(1<<2) << endl; // 0100

  //  cout << bitset<6>(3>>4) << endl; // 000000
  //
  //  cout << isPowerOfTwo(4) << endl;
  //  cout << countOneBits(6) << endl;
  cout << isKthSet(3, 2) << endl;
  return 0;
}
