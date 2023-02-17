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
    void dfs(std::vector<int>& myList, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(myList, root->left);
        myList.push_back(root->val);
        dfs(myList, root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> myList{};
        dfs(myList, root);
        return myList[k-1];
    }
};