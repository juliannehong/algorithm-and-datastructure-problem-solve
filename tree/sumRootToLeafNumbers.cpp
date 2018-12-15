// https://leetcode.com/problems/closest-binary-search-tree-value/description/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getNumber(const unordered_map<int,int>& parentTable, TreeNode* root) {
  int n = 0;
  int currVal = 0;
  int theDigit = root->val;
  while (parentTable.find(theDigit) != parentTable.end()){
    currVal = currVal + theDigit * pow(10, n);
    theDigit = parentTable.at(theDigit);
    n++;
  }
  currVal = currVal + theDigit * pow(10, n);
  return currVal;
}

bool isLeaf(TreeNode* root){
  return root->left == nullptr && root->right == nullptr;
}

void DFS(unordered_map<int,int>& parentTable, vector<int>& numList, TreeNode* root, TreeNode* parent) {
  if (root == nullptr)
    return ;
  if (parent != nullptr)
    parentTable[root->val] = parent->val;
  if (isLeaf(root))
    numList.push_back(getNumber(parentTable, root));
  else{
    DFS(parentTable, numList, root->left, root);
    DFS(parentTable, numList, root->right, root);
  }
}

int sumNumbers(TreeNode* root) {
  int theSum = 0;
  unordered_map<int, int> parentTable;
  vector<int> numList;
  DFS(parentTable, numList, root, nullptr);
  for (auto num : numList)
    theSum += num;
  return theSum;
}

int main() {
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(1);
  root->right = new TreeNode(0);
  cout << sumNumbers(root) << endl;
  
  TreeNode* root2 = new TreeNode(1);
  root2->right = new TreeNode(3);
  root2->left = new TreeNode(2);
  cout << sumNumbers(root2) << endl;
  
  return 0;
}
