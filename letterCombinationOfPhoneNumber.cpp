// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> helper(const unordered_map<char, string>& m, const string& digits, int index) {
  vector<string> re;
  string curr = m.at(digits[index]);
  if (index == 0) {
    for (char c : curr) {
      re.push_back({c});
    }
  } else {
    vector<string> temp = helper(m, digits, index - 1);
    for (auto c : curr) {
      for (auto str : temp) {
        re.push_back(str+=c);
      }
    }
  }
  return re;
}
vector<string> letterCombinations(string digits) {
  int count = digits.size() - 1;
    if (count == -1)
        return {};
  unordered_map<char, string> m;
  m['2'] = "abc";
  m['3'] = "def";
  m['4'] = "ghi";
  m['5'] = "jkl";
  m['6'] = "mno";
  m['7'] = "pqrs";
  m['8'] = "tuv";
  m['9'] = "wxyz";   
    
  return helper(m, digits, count);
}