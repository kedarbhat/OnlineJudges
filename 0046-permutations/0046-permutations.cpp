class Solution {
    vector<vector<int>> theResult;
    std::vector<bool> theUsedTracker;
    void dfs(const vector<int>& nums, std::size_t startIdx, std::string path) noexcept {
        if (startIdx == nums.size()) {
            theResult.emplace_back(vector<int>(path.cbegin(), path.cend()));
            return;
        }
        for (auto i = 0; i < theUsedTracker.size(); ++i) {
            if (theUsedTracker[i]) {
                continue;
            }
            theUsedTracker[i] = true;
            path += nums[i];
            dfs(nums, startIdx+1, path);
            path.pop_back();
            theUsedTracker[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        theUsedTracker.resize(nums.size());
        auto path = std::string{};
        dfs(nums, 0, path);
        return theResult;
    }
};