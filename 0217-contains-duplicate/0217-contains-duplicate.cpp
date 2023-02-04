class Solution {
public:
    bool containsDuplicate(const vector<int>& nums) {
        std::unordered_set<int> mySeenNums(nums.cbegin(), nums.cend());
        return nums.size() != mySeenNums.size();
    }
};