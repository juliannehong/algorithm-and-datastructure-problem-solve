// https://leetcode.com/problems/string-to-integer-atoi/description/
// O(n) O(1)
#include <unordered_map>
#include <iostream>
using namespace std;

int myAtoi(string str) {
  if (str.empty())
    return 0;
  unordered_map<char, int> m;
  bool started = false, neg = false;
 int ans = 0, temp = 0;
  for (char c : "0123456789"){m[c] = temp++;}
  for (char c : str){
    if (!started) {
      if (c == ' ') continue;
      else if (c == '-') {neg = true; started = true;}
      else if (c == '+') {started = true;}
      else if (m.find(c) != m.end()) {started = true; ans = m[c];}
      else break;
    } else if (started) {
      if (m.find(c) != m.end()) {
        int new_ans = ans*10 + m[c]; // overflow detect (new_ans < ans doesnt work for some reason!!)
        if (new_ans/10 != ans)
          return (neg) ? INT_MIN : INT_MAX;
        else
          ans = new_ans;
      } else {
        break;
      }
    }
  }
  return neg ?  -1*ans : ans;
}
