// https://leetcode.com/problems/valid-parentheses/description/
#include <iostream>
#include <stack>
using namespace std;

bool isValid (string s){
  stack<char> st;
  for (auto c : s){
    if (c == '{' || c == '(' || c == '[') {
      st.push(c);
    } else {
      if (st.empty()) return false;
      if (c == '}') {
        if (st.top() != '{') return false;
      } else if (c == ')') {
        if (st.top() != '(') return false;
      } else {
        if (st.top() != '[') return false;
      }
      st.pop();
    }
  }
  return (st.empty()) ? true : false;
}
