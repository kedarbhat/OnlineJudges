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
    int maxPathSumFound{0};
    int dfs(TreeNode* root) noexcept {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            maxPathSumFound = max(maxPathSumFound, root->val);
            return root->val;
        }
        auto left_path_sum = dfs(root->left);
        auto right_path_sum = dfs(root->right);
        maxPathSumFound = std::max({maxPathSumFound, root->val, root->val+left_path_sum+right_path_sum, root->val+left_path_sum, root->val+right_path_sum});
        return std::max({root->val, root->val+left_path_sum, root->val+right_path_sum, 0});
    }
public:
    int maxPathSum(TreeNode* root) noexcept {
        maxPathSumFound = root == nullptr ? 0 : root->val;
        dfs(root);
        return maxPathSumFound;
    }
};