/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  void dfs(TreeNode *root, int targetSum, std::vector<int> &path, std::vector<std::vector<int>> &res) noexcept {
    if (root == nullptr) {
      return;
    }
    path.push_back(root->val);
    targetSum -= root->val;
    if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
      res.push_back(path);
    }
    dfs(root->left, targetSum, path, res);
    dfs(root->right, targetSum, path, res);
    path.pop_back();
  }

 public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
    std::vector<std::vector<int>> res;
    std::vector<int> path;
    dfs(root, targetSum, path, res);
    return res;
  }
};