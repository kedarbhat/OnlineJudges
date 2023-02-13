class Solution {
public:
    bool containsDuplicate(const vector<int>& nums) noexcept {
        std::unordered_set<int> mySeenNums(nums.size());
        for (auto i : nums) {
            if (!mySeenNums.emplace(i).second) {
                return true;
            }
        }
        return false;
    }
};