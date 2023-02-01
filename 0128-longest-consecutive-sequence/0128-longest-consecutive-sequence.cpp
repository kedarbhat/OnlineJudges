class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        const std::unordered_set<int> uniqueNums(nums.cbegin(), nums.cend());
        auto longest = 0;
        for (auto num : nums) {
            if (uniqueNums.find(num-1) == uniqueNums.cend()) {
                auto current = 1;
                while (uniqueNums.find(num + current) != uniqueNums.cend()) {
                    ++current;
                }
                longest = std::max(longest, current);
            }
        }
        return longest;
    }
};