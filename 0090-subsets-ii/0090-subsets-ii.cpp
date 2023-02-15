class Solution {
    vector<vector<int>> theResult;
    void dfs(const std::vector<int>& nums, int startIdx, std::vector<int>& path) {
        theResult.emplace_back(path);
        for (auto i = startIdx; i < nums.size(); ++i) {
            if (i != startIdx && nums[i] == nums[i-1]) {
                continue;
            }
            path.emplace_back(nums[i]);
            dfs(nums, i+1, path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> path;
        dfs(nums, 0, path);
        return theResult;
    }
};