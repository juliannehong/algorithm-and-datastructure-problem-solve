https://leetcode.com/problems/valid-anagram/description/
using namespace std;    
    
bool isAnagram(string s, string t) {
  if (s.size() != t.size())
    return false;
  vector<int> alphabets(26);
  for (int i = 0; i < s.size(); ++i){
    alphabets[s[i] - 'a']++;
    alphabets[t[i] - 'a']--;
  }
  for (int c : alphabets) {
    if (c != 0)
      return false;
  }
  return true;
}