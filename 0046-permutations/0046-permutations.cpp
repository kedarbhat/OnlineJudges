class Solution {
    using PathT = std::vector<int>;
    std::vector<PathT> backtrack(int index, PathT& path, std::vector<bool>& usedIdxs, const PathT& nums) { 
        std::vector<PathT> result;
        if (path.size() == nums.size()) {
            result.push_back(path);
            return result;
        }
        for (auto idx = 0; idx < nums.size(); ++idx) {
            if (usedIdxs[idx]) {
                continue;
            }
            usedIdxs[idx] = true;
            path.push_back(nums[idx]);
            const auto& subResult {backtrack(idx, path, usedIdxs, nums)};
            std::move(subResult.cbegin(), subResult.cend(), std::back_inserter(result));
            path.pop_back();
            usedIdxs[idx] = false;
        }
        return result;
    }

public:
    vector<PathT> permute(const PathT& nums) {
        std::vector<PathT> result;
        if (nums.empty()) {
            return result;
        }
        std::vector<bool> usedIdxs(nums.size());
        for (auto idx = 0; idx < nums.size(); ++idx) {
            usedIdxs[idx] = true;
            auto myPath{PathT{nums[idx]}};
            myPath.reserve(nums.size());
            const auto& subResult = backtrack(idx, myPath, usedIdxs, nums);
            std::move(subResult.cbegin(), subResult.cend(), std::back_inserter(result));
            usedIdxs[idx] = false;
        }
        return result;
    }
};