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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::deque<TreeNode*> myQueue{root};
        std::vector<vector<int>> result;
        while (!myQueue.empty()) {
            const auto levelLength = myQueue.size();
            std::vector<int> levelResult;
            levelResult.reserve(levelLength);
            for (auto i = 0; i < levelLength; ++i) {
                const auto* myNode = myQueue.front();
                myQueue.pop_front();
                levelResult.push_back(myNode->val);
                if (myNode->left != nullptr) {
                    myQueue.push_back(myNode->left);
                }
                if (myNode->right != nullptr) {
                    myQueue.push_back(myNode->right);
                }
            }
            result.push_back(levelResult);
        }
        return result;
    }
};