class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        std::unordered_map<int, int> indexMap;
        std::vector<int> result(2);
        for (auto i = 0; i < nums.size(); ++i) {
            const auto complement = target-nums[i];
            const auto iter = indexMap.find(complement);
            if (iter != std::cend(indexMap)) {
                result[0] = std::get<1>(*iter);
                result[1] = i;
                break;
            }
            indexMap.emplace(nums[i], i);
        }
        return result;
    }
};