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
    static constexpr bool isSymmetric(TreeNode* left, TreeNode* right) noexcept {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return left->val == right->val && isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root != nullptr && isSymmetric(root->left, root->right);
    }
};