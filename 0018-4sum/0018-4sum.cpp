class Solution {
    vector<vector<int>> sortedTwoSum(const vector<int>& nums, int leftAnchor, int rightAnchor, int target) {
        int start = leftAnchor+1;
        int finish = rightAnchor-1;
        vector<vector<int>> result;
        while (start < finish) {
            std::array<std::int64_t, 4> candidates {nums[leftAnchor], nums[start], nums[finish], nums[rightAnchor]};
            const auto currentSum = std::reduce(candidates.cbegin(), candidates.cend(), std::int64_t{0}, std::plus<>{});
            if (currentSum == target) {
                result.emplace_back(vector<int>{nums[leftAnchor], nums[start], nums[finish], nums[rightAnchor]});
                ++start;
                while (start < finish && nums[start] == nums[start-1]) {
                    ++start;
                }
                 while (start < finish && nums[finish] == nums[finish-1]) {
                    --finish;
                }
            } else if (currentSum < target) {
                ++start;
            } else {
                --finish;
            }
        }
        return result;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = nums.size()-1; j >= i; --j) {
                if (j+1 < nums.size() && nums[j] == nums[j+1]) {
                    continue;
                }
                const auto& twoSumResult = sortedTwoSum(nums, i, j, target);
                std::move(twoSumResult.cbegin(), twoSumResult.cend(), std::back_inserter(result));
            }
        }
        return result;
    }
}; 