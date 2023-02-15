class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& aVector, const int aWindowSize) noexcept {
        std::deque<int> mySlidingWindow;
        std::vector<int> myResult;
        auto left = 0u;
        for (auto right = 0u; right < aVector.size(); ++right) {
            while (!mySlidingWindow.empty() && aVector[mySlidingWindow.back()] < aVector[right]) {
                mySlidingWindow.pop_back();
            }
            mySlidingWindow.push_back(right);
            if (left > mySlidingWindow.front()) {
                mySlidingWindow.pop_front();
            }
            if (right + 1 >= aWindowSize) {
                myResult.push_back(aVector[mySlidingWindow.front()]);
                ++left;
            }
        }
        return myResult;
    }
};