// https://leetcode.com/problems/intersection-of-two-arrays/description/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  unordered_set<int> memo;
  vector<int> res;
  for (auto num : nums1){
    memo.insert(num);
  }
  for (auto num : nums2){
    auto search = memo.find(num);
    if (search != memo.end()){
      memo.erase(num);
      res.push_back(num); // not to add duplicate num
    }
  }
  return res;
}