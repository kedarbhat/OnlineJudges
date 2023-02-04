class Solution {
public:
    bool containsDuplicate(const vector<int>& nums) {
        std::unordered_set<int> mySeenNums(nums.size());
        for (auto i : nums) {
            const auto& result = mySeenNums.emplace(i);
            if (!result.second) {
                return true;
            }
        }
        return false;
    }
};