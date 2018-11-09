// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string str) {
  unordered_map<char, int> m;
  int l = 0, r = 0, re = 0;
  while (r < str.size()){
    if (m.find(str[r]) != m.end()) {
      l = max(m[str[r]] + 1, l);
      m[str[r]] = r;
    } else {
      m.insert(make_pair(str[r], r));
    }
    re = max(re, r - l + 1);
    r++;
  }
  return re;
}
