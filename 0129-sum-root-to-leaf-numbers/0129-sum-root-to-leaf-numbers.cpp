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
    int sumNumbers(TreeNode* root, int currentSum = 0) {
        if (root == nullptr) {
            return currentSum;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val+10*currentSum;
        }
        if (root->left == nullptr) {
            return sumNumbers(root->right, root->val+10*currentSum);
        }
        if (root->right == nullptr) {
            return sumNumbers(root->left, root->val+10*currentSum);
        }
        return sumNumbers(root->left, root->val+10*currentSum) + sumNumbers(root->right, root->val+10*currentSum);
    }
};