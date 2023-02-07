class Solution {
    std::vector<std::vector<int>> theResult;
    void backtrack(int startIndex, std::string path) noexcept { 
        if (startIndex == path.size()) {
            theResult.emplace_back(std::vector<int>(path.cbegin(), path.cend()));
        }
        for (auto i = startIndex; i < path.size(); ++i) {
            std::swap(path[i], path[startIndex]);
            backtrack(startIndex+1, path);
            std::swap(path[i], path[startIndex]);
        }
    }

public:
    std::vector<std::vector<int>> permute(const std::vector<int>& nums) noexcept {
        if (nums.empty()) {
            return theResult;
        }
        backtrack(0, std::string(nums.cbegin(), nums.cend()));
        return theResult;
    }
};