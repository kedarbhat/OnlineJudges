class Solution {
    vector<vector<int>> theResult;
    vector<int> theCandidates;
    int theTarget;
    void dfs(const int currentSum, const int currentIndex, std::vector<int>& path) noexcept {
        if (currentSum > theTarget) {
            return;
        }
        if (currentSum == theTarget) {
            theResult.emplace_back(path);
        }
        for (auto i = currentIndex; i < theCandidates.size(); ++i) {
            path.emplace_back(theCandidates[i]);
            dfs(currentSum+theCandidates[i], i, path);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(const vector<int>& candidates, int target) noexcept {
        std::copy(candidates.cbegin(), candidates.cend(), std::back_inserter(theCandidates));
        theTarget = target;
        auto myPath = std::vector<int>{};
        dfs(0, 0, myPath);
        return theResult;    
    }
};