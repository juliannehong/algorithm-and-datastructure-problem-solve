// STL cheatsheet
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#define STRING 0
#define UNORDERED_SET 0
#define UNORDERED_MAP 0
#define QUEUE 0
#define HEAP 0
using namespace std;


int main() {
  

  int randomInt = 18;
  string numberStr = to_string(randomInt);
  string randomNumberStr = "34";
  int random = stoi(randomNumberStr);
  
#if STRING
  string str = "its kinda cold but its okay";
  string substr1 = str.substr(4,3); // kin
  int pos = str.find("cold");
  string substr2 = str.substr(pos);
  cout << substr2<< endl;
#endif
  
#if UNORDERED_SET
  unordered_set<int> s;
  s.insert(1);
  s.insert(3);
  s.insert(5);
  s.erase(3);
  for (auto elem : s) {
    cout << elem << endl;
  }
#endif
  
#if UNORDERED_MAP
  unordered_map<int, char> m;
  m.insert({2,'a'});
  m.insert(make_pair(4,'b'));
  m[5] = 'c';
  for (auto elem : m){
    cout << elem.first << ", " << elem.second << endl;
  }
  cout << m.at(5) << endl;
  auto search = m.find(4);
  cout << search->second << endl;
#endif

#if QUEUE
  queue<int> q;
  q.push(4);
  q.push(5);
  cout << q.front() << endl;
  q.pop();
  cout << q.front() << endl;
#endif
  
#if HEAP
  priority_queue<int> maxheap; // by default larger at the top
  maxheap.push(4);
  maxheap.push(5);
  maxheap.push(3);
  while (!maxheap.empty()){
    cout << maxheap.top() << endl;
    maxheap.pop();
  }
  
  priority_queue<int, vector<int>, greater<int>> minheap; // min heap
  minheap.push(4);
  minheap.push(5);
  minheap.push(3);
  while (!minheap.empty()){
    cout << minheap.top() << endl;
    minheap.pop();
  }
#endif
  const int N = 5;
  vector<int> zeros(N, 0);
  vector<int> nums {1,6,8,3,5,7};
  cout << "======= subarray ===========" << endl;
  vector<int> subArray (nums.begin()+3, nums.begin()+5); // {3,5}
  for (int i : subArray) {
    cout << i << endl;
  }
  cout << "======= sort ==========" << endl;
  sort(nums.begin(), nums.end());
  sort(nums.begin(), nums.end(), greater<int>()); // ascending order by default
  for (int i : nums) {
    cout << i << endl;
  }
    cout << "======= min max search ===========" << endl;
  auto search = max_element(nums.begin(), nums.end());
  if (search != nums.end())
    cout << *search << endl;
 

  return 0;
}
