// https://leetcode.com/problems/binary-search-tree-iterator/description/ 
#include <queue>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    if (root != nullptr)
      queueConstruct(root);
  }
  
  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !_q.empty();
  }

  /** @return the next smallest number */
  int next() {
    if (!_q.empty()) {
      TreeNode* res = _q.front();
      _q.pop();
    }
  }
private:
  queue<TreeNode*> _q;
  void queueConstruct(TreeNode* root) {
    if (root->left != nullptr)
      queueConstruct(root->left);
    _q.push(root);
    if (root->right != nullptr)
      queueConstruct(root->right);
  }
};