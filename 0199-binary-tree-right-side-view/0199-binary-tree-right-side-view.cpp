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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        std::queue<TreeNode*> myQueue;
        myQueue.push(root);
        while (!myQueue.empty()) {
            const auto levelSize = myQueue.size();
            for (auto i = 0; i < levelSize; ++i) {
                const auto* myNode = myQueue.front();
                myQueue.pop();
                if (i+1 == levelSize) {
                    result.push_back(myNode->val);
                }
                if (myNode->left != nullptr) {
                    myQueue.push(myNode->left);
                }
                if (myNode->right != nullptr) {
                    myQueue.push(myNode->right);
                }
            }
        }
        return result;
    }
};