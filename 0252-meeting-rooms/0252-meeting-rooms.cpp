class Solution {
    [[gnu::pure]] static bool overlap(const vector<int>& lhs, const vector<int>& rhs) noexcept {
        return lhs[1] > rhs[0];
    }

public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        auto iter = std::adjacent_find(intervals.cbegin(), intervals.cend(), overlap);
        return iter == intervals.cend();
    }
};