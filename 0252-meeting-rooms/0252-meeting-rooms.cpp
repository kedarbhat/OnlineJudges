class Solution {
    static bool overlap(const std::vector<int>& lhs, const std::vector<int>& rhs) noexcept {
        return lhs[1] > rhs[0];
    }

public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) noexcept {
        std::sort(intervals.begin(), intervals.end());
        return intervals.cend() == std::adjacent_find(intervals.cbegin(), intervals.cend(), overlap);
    }
};