class Solution {
public:
    int maxArea(const vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        auto maxWaterAmount = 0;
        while (left < right) {
            auto currentAmount = std::min(height[left], height[right]) * (right-left);
            maxWaterAmount = std::max(currentAmount, maxWaterAmount);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxWaterAmount;
    }
};