/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    static constexpr TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) noexcept {
        if (root == nullptr) {
            return nullptr;
        } 
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left != nullptr ? left : root;
        }
    }
};