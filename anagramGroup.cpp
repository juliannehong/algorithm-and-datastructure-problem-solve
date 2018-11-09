https://leetcode.com/problems/group-anagrams/description/
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> re;
  unordered_map<string, vector<string>> m;
  for (string str : strs) {
    string temp = str;
    sort(temp.begin(), temp.end());
    m[temp].push_back(str);
  }
  
  for (auto i = m.begin(); i != m.end(); ++i){
    re.push_back(i->second);
  }
  return re;
}