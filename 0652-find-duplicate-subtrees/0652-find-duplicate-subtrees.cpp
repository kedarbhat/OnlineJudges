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
    std::unordered_map<std::string, int> theTreeCounts;
    std::vector<TreeNode*> theDuplicates;
    std::string findDuplicates(TreeNode* node) noexcept {
        if (node == nullptr) {
            return "";
        } 
        std::string subTree = std::to_string(node->val) + "," + findDuplicates(node->left) + "," + findDuplicates(node->right);
        ++theTreeCounts[subTree];
        if (theTreeCounts[subTree] == 2) {
             theDuplicates.push_back(node);
        }
        return subTree;
    }
public:
    std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        findDuplicates(root);
        return theDuplicates;        
    }
};