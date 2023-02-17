class Solution {
public:
    int largestRectangleArea(const std::vector<int>& heights) noexcept {
        int n = heights.size();
        std::vector<int> left(n);
        std::vector<int> right(n);
        std::stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            max_area = std::max(max_area, heights[i] * (right[i] - left[i] - 1));
        }
        return max_area;        
    }
};