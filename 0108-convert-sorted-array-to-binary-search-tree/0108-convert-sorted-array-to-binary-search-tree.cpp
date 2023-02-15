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
    using IteratorT = std::vector<int>::const_iterator;
    static TreeNode* sortedArrayToBST(IteratorT start, IteratorT finish) noexcept {
        if (start == finish) {
            return nullptr;
        }
        auto mid = std::distance(start, finish)/2;
        auto* resultNode = new TreeNode(*std::next(start, mid));
        resultNode->left = sortedArrayToBST(start, std::next(start, mid));
        resultNode->right = sortedArrayToBST(std::next(start, mid+1), finish);
        return resultNode;
    }

public:
    TreeNode* sortedArrayToBST(const std::vector<int>& nums) noexcept {
        return sortedArrayToBST(nums.cbegin(), nums.cend());
    }
};