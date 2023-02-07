class Solution {
    vector<vector<int>> theResult;
    std::unordered_map<int, int> theCounter;
    void dfs(const vector<int>& nums, std::size_t startIdx, vector<int>& path) noexcept {
        if (startIdx == nums.size()) {
            theResult.emplace_back(vector<int>(path));
            return;
        }
        for (auto& [myNum, myCount] : theCounter) {
            if (myCount == 0) {
                continue;
            }
            --myCount;
            path.push_back(myNum);
            dfs(nums, startIdx+1, path);
            path.pop_back();
            ++myCount;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto num : nums) {
            ++theCounter[num];
        }
        auto path = vector<int>{};
        dfs(nums, 0, path);
        return theResult;
    }
};