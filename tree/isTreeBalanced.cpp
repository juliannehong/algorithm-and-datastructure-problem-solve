using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeStatus {
  bool balanced;
  int height;
};

TreeStatus helper(TreeNode* root) {
  if (root == nullptr) {
    return {true, 0};
  }
  TreeStatus leftStatus = helper(root->left);
  TreeStatus rightStatus = helper(root->right);

  if (leftStatus.balanced && rightStatus.balanced && abs(leftStatus.height - rightStatus.height) <= 1){
    return {true, max(leftStatus.height, rightStatus.height) + 1};
  } else {
    return {false, 0};
  }
}

bool isBalanced(TreeNode* root) {
  return helper(root).balanced;
}