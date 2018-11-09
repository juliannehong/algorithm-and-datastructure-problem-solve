// longest common substring
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

/* iteration */
int longestCommonSubstring(string str1, string str2) {
  int re = 0;
  int m[str1.size()][str2.size()];
  for (int i = 0; i < str1.size(); ++i){
    for (int j = 0; j < str2.size(); ++j) {
      if (str1[i] == str2[j]) {
        if (i == 0 || j == 0){
          m[i][j] = 1;
        } else {
          m[i][j] = m[i-1][j-1] + 1;
        }
        re = (m[i][j] > re) ? m[i][j] : re;
      } else {
        m[i][j] = 0;
      }
    }
  }
  return re;
}
/* recursion */
int helper(string& str1, string& str2, int i, int j){
  if (i == 0 || j == 0) {
    if (str1[i] && str2[j])
      return 1;
    else
      return 0;
  }
  if (str1[i] == str2[j]){
    return helper(str1, str2, i - 1, j - 1) + 1;
  } else {
    return max(helper(str1, str2, i - 1, j), helper(str1, str2, i, j - 1));
  }
}

int longestCommonSubstringRecursion(string str1, string str2) {
  return helper(str1, str2, str1.size() - 1, str2.size() - 1);
}

int main(){
  cout << longestCommonSubstring("GeeksforGeeks", "GeeksQuiz") << endl;
  cout << longestCommonSubstringRecursion("GeeksforGeeks", "GeeksQuiz") << endl;
  return 0;
}
