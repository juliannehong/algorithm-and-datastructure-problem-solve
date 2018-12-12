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
/* Using Binary Tree type solution */
struct Status {
  int length;
  string str;
};

Status LCSHelper(const string& str1, const string& str2, int m, int n){
  if (m < 0 || n < 0)
    return {0, ""};
  if (str1[m] == str2[n]) {
    Status s = LCShelper(str1, str2, m-1, n-1);
    return {s.length + 1, s.str + str1[m]};
  }
  else {
    Status s1 = LCShelper(str1, str2, m-1, n);
    Status s2 = LCShelper(str1, str2, m, n-1);
    return (s1.length > s2.length) ? s1 : s2;
  }
}
string longestCommonSubstrTreeThought(string str1, string str2){
  return LCShelper(str1, str2, str1.size()-1, str2.size()-1).str;
}

int main() {
  cout << longestCommonSubstr("AGGTAB","GXTXAYB") << endl;
  cout << longestCommonSubstr("ABCDGH","AEDFHR") << endl;
  return 0;
}


int main(){
  cout << longestCommonSubstring("GeeksforGeeks", "GeeksQuiz") << endl;
  cout << longestCommonSubstringRecursion("GeeksforGeeks", "GeeksQuiz") << endl;
  return 0;
}
