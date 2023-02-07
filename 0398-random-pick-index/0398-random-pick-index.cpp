class Solution {
    std::unordered_map<int, std::vector<int>> theIndexMap;

public:
    explicit Solution(const vector<int>& nums) noexcept {
        for (auto i = 0; i < nums.size(); ++i) {
            theIndexMap[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) noexcept {
        return theIndexMap[target][std::rand() % theIndexMap[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */