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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        std::deque<TreeNode*> queue{root};
        bool rightToLeft = false;
        while (!queue.empty()) {
            auto levelSize = queue.size();
            vector<int> levelResult;
            for (auto i = 0; i < levelSize; ++i) {
                auto* currentNode = queue.front();
                queue.pop_front();
                levelResult.push_back(currentNode->val);
                if (currentNode->left != nullptr) {
                    queue.push_back(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push_back(currentNode->right);
                }
            }
            if (rightToLeft) {
                std::reverse(levelResult.begin(), levelResult.end());
            }
            rightToLeft = !rightToLeft;
            result.emplace_back(levelResult);
        }
        return result;
    }
};