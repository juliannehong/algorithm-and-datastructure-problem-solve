// https://leetcode.com/problems/two-sum/description/
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> m; // {value, index}
  for (int i = 0; i < nums.size(); i++) {
    int comp = target - nums[i];
    if (m.find(comp) != m.end())
      return {i, m[comp]};
    else
      m[nums[i]] = i;
  }
  return {};
}

vector<vector<int>> threeSum(vector<int>& nums){
  vector<vector<int>> re;
  sort(nums.begin(), nums.end());
  for (int l = 0; l < nums.size() - 3; ++l) {
    if (nums[l] >= 0) break;
    if (l != 0 && nums[l] == nums[l - 1]) continue;
    int comp = -1 * nums[l], m = l + 1, r = nums.size() - 1;
    while (m < r){
      int twoSum = nums[m] + nums[r];
      if (twoSum == comp) {
        re.push_back({nums[l], nums[m], nums[r]});
        ++m;
        while (nums[m-1] == nums[m] && m < r)
          ++m;
      }
      else if (twoSum > comp)
        --r;
      else
        ++m;
    }
  }
  return re;
}
