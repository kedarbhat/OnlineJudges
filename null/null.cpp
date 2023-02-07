
static auto pointDistance = [](const vector<int>& point) noexcept { 
    return point[0]*point[0] + point[1]*point[1]; 
};

template<>
struct std::less<vector<int>> {
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const noexcept {
        return pointDistance(lhs) < pointDistance(rhs);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq(points.cbegin(), next(points.cbegin(), k));
        for (auto i = k; i < points.size(); ++i) {
            if (pointDistance(points[i]) < pointDistance(pq.top())) {
                pq.pop();
                pq.push(points[i]);
            } 
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());        
            pq.pop();
        }
        return result;
    }
};