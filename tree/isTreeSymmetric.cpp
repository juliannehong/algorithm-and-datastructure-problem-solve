using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool helper(TreeNode* sub1, TreeNode* sub2) {
  if (sub1 == nullptr && sub2 == nullptr)
    return true;
  else if (sub1 == nullptr || sub2 == nullptr)
    return false;
  else 
    return (sub1->val == sub2->val && helper(sub1->left, sub2->right) && helper(sub1->right, sub2->left));
}

bool isTreeSymmetric(TreeNode* root) {
  if (root == nullptr)
    return true;
  return helper(root->left, root->right);
}