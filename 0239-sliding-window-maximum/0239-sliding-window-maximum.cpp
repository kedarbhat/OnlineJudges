class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int windowSize) {
        deque<int> slidingWindow;
        vector<int> result;
        auto left = 0;
        for (auto right = 0; right < v.size(); ++right) {
            // pop smaller values from q
            while (!slidingWindow.empty() && v[slidingWindow.back()] < v[right]) {
                slidingWindow.pop_back();
            }
            slidingWindow.push_back(right);
            // remove left val from window
            if (left > slidingWindow.front()) {
                slidingWindow.pop_front();
            }
            if (right + 1 >= windowSize) {
                result.push_back(v[slidingWindow.front()]);
                ++left;
            }
        }
        return result;
    }
};