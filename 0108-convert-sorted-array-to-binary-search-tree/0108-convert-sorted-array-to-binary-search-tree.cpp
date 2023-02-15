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
    TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    auto mid = nums.size() / 2;
    auto root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(std::vector<int>(nums.begin(), nums.begin() + mid));
    root->right = sortedArrayToBST(std::vector<int>(nums.begin() + mid + 1, nums.end()));
    return root;
    }
};