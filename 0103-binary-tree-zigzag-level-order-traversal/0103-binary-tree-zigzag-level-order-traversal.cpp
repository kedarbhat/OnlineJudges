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
        bool leftToRight = false;
        while (!queue.empty()) {
            auto levelSize = queue.size();
            std::deque<int> levelResult;
            for (auto i = 0; i < levelSize; ++i) {
                auto* currentNode = queue.front();
                queue.pop_front();
                if (leftToRight) {
                    levelResult.push_front(currentNode->val);
                } else {
                    levelResult.push_back(currentNode->val);
                }
                if (currentNode->left != nullptr) {
                    queue.push_back(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push_back(currentNode->right);
                }
            }
            leftToRight = !leftToRight;
            result.emplace_back(std::vector<int>(levelResult.begin(), levelResult.end()));
        }
        return result;
    }
};