class Solution {
    static auto overlap(const std::vector<int>& lhs, const std::vector<int>& rhs) noexcept {
        return lhs[1] > rhs[0];
    }
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) noexcept {
        std::sort(intervals.begin(), intervals.end());
        auto numOverlaps = 0;
        for (auto i = 0; i + 1 < intervals.size(); ++i) {
            if (overlap(intervals[i], intervals[i+1])) {
                if (intervals[i][1] < intervals[i+1][1]) {
                   std::swap(intervals[i], intervals[i+1]);
                }
                ++numOverlaps;
            }
        }
        return numOverlaps;
    }
};