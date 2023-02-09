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
public:
    static constexpr int goodNodes(TreeNode* root, int maxSoFar = -10001) noexcept {
        if (root == nullptr) {
            return 0;
        }
        auto newMaxSoFar = std::max(root->val, maxSoFar);
        return (root->val >= maxSoFar) * 1 + goodNodes(root->left, newMaxSoFar) + goodNodes(root->right, newMaxSoFar);
        
    }
};