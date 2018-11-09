// https://leetcode.com/problems/count-primes/description/ 
// O(n/2 + n/3 + n/4 + ... + n/n), O(n)
#include <vector>

int countPrimes(int n) {
  vector<bool> isPrime(n+1, true);
  int result = 0;
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      result++;
      for (int j = i*2; j <= n; j += i){
        isPrime[j] = false;
      }
    }
  }
  return result;
}