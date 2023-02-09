class Solution {
    vector<vector<int>> result;
    void dfs(const vector<int>& nums, int startIdx, std::vector<int> current) {
        result.emplace_back(std::vector<int>{current});
        for (auto i = startIdx; i < nums.size(); ++i) {
            current.emplace_back(nums[i]);
            dfs(nums, i+1, current);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        std::vector<int> current;
        current.reserve(10);
        dfs(nums, 0, current);
        return result;
    }
};