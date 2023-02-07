class Solution {      
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[0] < rhs[0];
        });
        std::priority_queue<int, vector<int>, std::greater<>> heap;
        heap.push(intervals[0][1]);
        for (auto i = 1; i < intervals.size(); ++i) {
            if (heap.top() <= intervals[i][0]) {
                heap.pop();
            }
            heap.push(intervals[i][1]);
        }
        return heap.size();
    }
};