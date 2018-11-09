#include <vector>
using namespace std;

vector<int> merge (vector<int>& A, vector<int>& B) {
  vector<int> re;
  int a = b = 0;
  while (a < A.size() && b < B.size()) {
    if (A[a] <= B[b]) {
      re.push_back(A[a++]);
    } else {
      re.push_back(B[b++]);
    }
  }
  while (a < A.size()) {
    re.push_back(A[a++]);
  } 
  while (b < B.size()) {
    re.push_back(B[b]);
  } 
  return re;
}

vector<int> merge_sort(vector<int>& nums){
  if (nums.size() == 1 || nums.size() == 0)
    return nums;
  int mid = nums.size() / 2;
  vector<int> l (nums.begin(), nums.begin() + mid);
  vector<int> r (nums.begin() + mid, nums.end());
  return merge(merge_sort(l), merge_sort(r));
}