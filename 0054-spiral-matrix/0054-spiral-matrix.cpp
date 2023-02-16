class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) noexcept {
        std::vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (auto i = left; i <= right; ++i) {
                result.emplace_back(matrix[top][i]);
            }
            ++top;
            for (auto i = top; i <= bottom; ++i) {
                result.emplace_back(matrix[i][right]);
            }
            --right;
            if (top <= bottom) {
                for (auto i = right; i >= left; --i) {
                    result.emplace_back(matrix[bottom][i]);
                }
                --bottom;
            }
            if (left <= right) {
                for (auto i = bottom; i >= top; --i) {
                    result.emplace_back(matrix[i][left]);
                }
                ++left;
            }
        } 
        return result;       
    }
};