#include <iostream>
using namespace std;

bool isPowerOfTwo(int x) {
  while (x % 2 == 0) x /= 2;
  return x == 1;
}

int countOneBits(int x) {
  int result = 0;
  while (x / 2 != 0) {
    if (x % 2 == 1)
      result++;
    x /= 2;
  }
  return result;
}

int main(){
//  cout << bitset<5>(3) << endl; // 00011
//  cout << bitset<4>(1<<2) << endl; // 0100
//  cout << bitset<6>(3>>4) << endl; // 000000
//  
  cout << isPowerOfTwo(4) << endl;
  cout << countOneBits(1) << endl;
  return 0;
}
