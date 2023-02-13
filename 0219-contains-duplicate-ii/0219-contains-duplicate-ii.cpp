class Solution {
public:
    bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> myIndexMap;
        for (auto i = 0; i < nums.size(); ++i) {
            if (auto iter = myIndexMap.find(nums[i]); iter != myIndexMap.cend()) {
                if (i - iter->second <= k) {
                    return true;
                }
            }
            myIndexMap[nums[i]] = i;
        }
        return false;
    }
};