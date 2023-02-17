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
    std::vector<TreeNode*> generateTrees(int start, int finish) noexcept {
        std::vector<TreeNode*> trees;
        if(start > finish) {
            trees.push_back(nullptr);
            return trees;
        }
        for(int i = start; i <= finish; i++) {
            std::vector<TreeNode*> leftTrees = generateTrees(start, i-1);
            std::vector<TreeNode*> rightTrees = generateTrees(i+1, finish);
            for(auto leftTree : leftTrees) {
                for(auto rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }

public:
    std::vector<TreeNode*> generateTrees(int n) noexcept {
        if (n == 0) {
            return std::vector<TreeNode*>{};
        }
        return generateTrees(1, n);
    }
};