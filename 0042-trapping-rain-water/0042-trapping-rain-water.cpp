class Solution {
    std::vector<int> computeMaxLeftSideHeights(const std::vector<int>& wallHeights) const noexcept {
        std::vector<int> maxWaterHeights(wallHeights.size());
        maxWaterHeights[0] = wallHeights[0];
        for (std::size_t i = 1; i < wallHeights.size(); ++i) {
            maxWaterHeights[i] = std::max(maxWaterHeights[i-1], wallHeights[i]);
        }
        return maxWaterHeights;
    }

        std::vector<int> computeMaxRightSideHeights(const std::vector<int>& wallHeights) const noexcept {
        std::vector<int> maxWaterHeights(wallHeights.size());
        maxWaterHeights[wallHeights.size()-1] = wallHeights[wallHeights.size()-1];
        for (int i = static_cast<int>(wallHeights.size())-2; i >= 0; --i) {
            maxWaterHeights[i] = std::max(maxWaterHeights[i+1], wallHeights[i]);
        }
        return maxWaterHeights;
    }
public:
    int trap(const std::vector<int>& wallHeights) {
        const auto& maxLeftSideWaterHeights{computeMaxLeftSideHeights(wallHeights)};
        const auto& maxRightSideWaterHeights{computeMaxRightSideHeights(wallHeights)};
        int ans = 0;
        for (std::size_t i = 0; i < wallHeights.size(); ++i) {
            ans += std::min(maxLeftSideWaterHeights[i], maxRightSideWaterHeights[i]) - wallHeights[i];
        }
        return ans;
    }
};