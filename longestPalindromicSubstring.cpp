// https://leetcode.com/problems/longest-palindromic-substring/description/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// It also returns the length of the longest palindrome
string longestPalindrome(string s)
{
  int N = s.size();
  
  vector<vector<bool>> table(N, vector<bool>(N, false));
  string currentMax;
  currentMax = s[0];
  for (int i = 0; i < N; ++i)
    table[i][i] = true;
  
  // check for sub-string of length 2.
  for (int i = 0; i < N-1; ++i) {
    if (s[i] == s[i+1])
    {
      table[i][i+1] = true;
      currentMax = s.substr(i, 2);
    }
  }
  
  // Check for lengths greater than 2. k is length
  // of substring
  for (int k = 3; k <= N; ++k)
  {
    // Fix the starting index
    for (int i = 0; i < N-k+1 ; ++i)
    {
      int j = i + k - 1;
      if (table[i+1][j-1] && s[i] == s[j])
      {
        table[i][j] = true;
        
        if (k > currentMax.size())
        {
          currentMax = s.substr(i, k);
        }
      }
    }
  }
  return currentMax; // return length of LPS
}

int main() {
  cout << longestPalindrome("forgeeksskeegfor") << endl;
  return 0;
}
