// https://leetcode.com/problems/rotate-image/description/
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
  if (nums.size() == 0)
    return 0;
  priority_queue<int> pq;
  for (int num : nums){
    pq.push(num);
  }
  int count = 0;
  while (!pq.empty() && count < k - 1){
    pq.pop();
    count++;
  }
  return pq.top();
}