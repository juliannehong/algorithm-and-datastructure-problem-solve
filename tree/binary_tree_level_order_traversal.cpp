// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> re;
  if (root == nullptr)
    return re;
  queue<TreeNode*> q1, q2;
  q1.push(root);
  while (!q1.empty() || !q2.empty()) {
    vector<int> levelVector; // store values for each level
    while (!q1.empty()) {
      TreeNode* curr = q1.front();
      q1.pop();
      levelVector.push_back(curr->val);
      if (curr->left != nullptr) { q2.push(curr->left); }
      if (curr->right != nullptr) { q2.push(curr->right); }
    }
    if (!levelVector.empty()) {
      re.push_back(levelVector);
      levelVector.clear();
    }
    while (!q2.empty()){
      TreeNode* curr = q2.front();
      q2.pop();
      levelVector.push_back(curr->val);
      if (curr->left != nullptr) { q1.push(curr->left); }
      if (curr->right != nullptr) { q1.push(curr->right); }
    }
    if (!levelVector.empty()) {
      re.push_back(levelVector);
    }
  }
  return re;
}
