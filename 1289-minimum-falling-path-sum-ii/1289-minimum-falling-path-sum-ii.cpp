class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        auto firstMin = 0;
        auto secondMin = 0;
        auto prevMinIndex = -1;
        for (const auto &row : grid) {
            auto currentFirstMin = std::numeric_limits<int>::max();
            auto currentSecondMin = std::numeric_limits<int>::max();
            auto currentMinIndex = -1;
            for (auto j = 0; j < row.size(); ++j) {
                auto currentMin = j != prevMinIndex ? firstMin : secondMin;
                if (row[j] + currentMin < currentFirstMin) {
                    currentSecondMin = currentFirstMin;
                    currentFirstMin = row[j] + currentMin;
                    currentMinIndex = j;
                } else {
                    currentSecondMin = std::min(currentSecondMin, row[j] + currentMin);
                }
            }
            firstMin = currentFirstMin;
            secondMin = currentSecondMin;
            prevMinIndex = currentMinIndex;
        }
        return firstMin;
    }
};