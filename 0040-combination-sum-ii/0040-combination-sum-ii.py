class Solution {
    std::vector<std::vector<int>> theResult;
    std::vector<int> theCandidates;
    int theTarget;
    void dfs(int startIdx, std::vector<int>& currentPath, int currentSum) noexcept {
        if (currentSum > theTarget) {
            return;
        }
        if (currentSum == theTarget) {
            theResult.emplace_back(currentPath);
            return;
        }
        for (int i = startIdx; i < theCandidates.size(); ++i) {
            if (i > startIdx && theCandidates[i] == theCandidates[i-1]) {
                continue;
            }
            currentPath.emplace_back(theCandidates[i]);
            dfs(i+1, currentPath, currentSum + theCandidates[i]);
            currentPath.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> combinationSum2(const std::vector<int>& candidates, int target) noexcept {
        std::copy(candidates.cbegin(), candidates.cend(), std::back_inserter(theCandidates));
        std::sort(theCandidates.begin(), theCandidates.end());
        theTarget = target;
        std::vector<int> path;
        dfs(0, path, 0);
        return theResult;
    }
};