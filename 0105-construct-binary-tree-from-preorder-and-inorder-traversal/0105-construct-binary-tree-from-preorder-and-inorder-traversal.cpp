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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        auto root = new TreeNode(preorder[0]);
        auto rootIdx = 0u;
        for (auto i = 0u; i < inorder.size(); ++i) {
            if (inorder[i] == preorder[0]) {
                rootIdx = i;
                break;
            }
        }
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+rootIdx);
        vector<int> leftInorder(inorder.begin(), inorder.begin()+rootIdx);
        vector<int> rightPreorder(preorder.begin()+1+rootIdx, preorder.end());
        vector<int> rightInorder(inorder.begin()+rootIdx+1, inorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};