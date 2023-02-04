class Solution {
public:
    bool containsDuplicate(const vector<int>& nums) {
        return nums.size() != std::unordered_set<int>(nums.cbegin(), nums.cend()).size();
    }
};