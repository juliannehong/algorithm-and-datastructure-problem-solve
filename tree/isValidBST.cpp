#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool validBSTWithInOrder(TreeNode* root, int currentVal) {
  if (root == nullptr)
    return true;
  if (validBSTWithInOrder(root->left, currentVal)) {
    if (currentVal < root->val){
      currentVal = root->val;
      return validBSTWithInOrder(root->right, currentVal);
    }
  }
  return false;
}

bool validBSTWithInOrder(TreeNode* root) {
  return validBSTWithInOrder(root, INT_MIN);
}

bool validBSTWithMinMaxRange(TreeNode* root, int min, int max){
  if (root == nullptr)
    return true;
  if (root->val > max || root->val < min)
    return false;
  if (!validBSTWithMinMaxRange(root->left, min, root->val) || !validBSTWithMinMaxRange(root->right, root->val, max))
    return false;
  return true;
}

bool validBSTWithMinMaxRange(TreeNode* root) {
  return validBSTWithMinMaxRange(root, INT_MIN, INT_MAX);
}

