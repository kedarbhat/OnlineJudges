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
    static constexpr bool isSameTree(TreeNode* left, TreeNode* right) noexcept {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return left->val == right->val && isSameTree(left->left, right->left) && isSameTree(left->right, right->right);
    }
public:
    static constexpr bool isSubtree(TreeNode* root, TreeNode* subRoot) noexcept {
        if (root == nullptr) {
            return false;
        }
        if (subRoot == nullptr) {
            return true;
        }
        if (root->val == subRoot->val && isSameTree(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    } 
};