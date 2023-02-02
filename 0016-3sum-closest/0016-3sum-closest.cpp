class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        auto result = std::reduce(nums.cbegin(), nums.cbegin()+3, 0);
        auto minDifferenceFound = std::abs(result-target);
        for (auto i = 0; i < nums.size(); ++i) {
            int lhs = i+1;
            int rhs = nums.size()-1;
            while (lhs < rhs) {
                auto lhs_num = nums[lhs];
                auto rhs_num = nums[rhs];
                auto currentSum = nums[i] + lhs_num + rhs_num;
                if (currentSum == target) {
                    return currentSum;
                }
                if (currentSum > target) {
                    --rhs;
                } else {
                    ++lhs;
                }
                const auto currentDifference = std::abs(currentSum-target);
                if (currentDifference < minDifferenceFound) {
                    minDifferenceFound = currentDifference;
                    result = currentSum;
                }
            }
        }
        return result;
    }
};