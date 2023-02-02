class Solution {
    auto twoSum(const vector<int>& nums, const std::size_t start) {
        std::vector<std::vector<int>> result;
        auto left = start+1;
        auto right = nums.size()-1;
        while (left < right) {
            const auto currentSum = nums[left]+nums[right]+nums[start];
            if (currentSum == 0) {
                result.emplace_back(vector<int>{nums[start], nums[left], nums[right]});
                ++left;
                while (left < right && nums[left] == nums[left-1]) {
                    ++left;
                }
            } else if (currentSum > 0) {
                --right;
            } else {
                ++left;
            }
        }
        return result;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            auto twoSumResult = twoSum(nums, i);
            std::move(std::cbegin(twoSumResult), std::cend(twoSumResult), std::back_inserter(result));
        }
        return result;
    }
};