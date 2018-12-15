// https://leetcode.com/problems/closest-binary-search-tree-value/description/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int helper(TreeNode* root, double target, int prevVal){
  if (root == nullptr)
    return prevVal; // shouldn't happen, but in case no closest value found, return -1
  double prevDiff = abs(target - prevVal), currDiff = abs(target - root->val);
  if (prevDiff > currDiff)
    prevVal = root->val;// previously we hit the closest
  if (target <= root->val)
    return helper(root->left, target, prevVal);
  else
    return helper(root->right, target, prevVal);
}

int closestValue(TreeNode* root, double target) {
  if (root == nullptr)
    return -1;
  return helper(root, target, root->val);
}
int main() {
 
  return 0;
}
