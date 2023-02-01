class Solution {
    using PointT = vector<int>;
    using SlopeT = double;
    using CountT = int;
    static constexpr auto calcSlope(const PointT& lhs, const PointT& rhs) noexcept {
        if (lhs[0] == rhs[0]) {
            constexpr auto verticalSlope{std::numeric_limits<SlopeT>::infinity()};
            return verticalSlope;
        }
        return static_cast<SlopeT>(lhs[1]-rhs[1])/(lhs[0]-rhs[0]);
    }
public:
    int maxPoints(const vector<PointT>& points) {
        auto maxCollinearPoints = 0;
        for (auto i{0u}; i < points.size(); ++i) {
            std::unordered_map<SlopeT, CountT> slopeCounts;
            auto identicalPoints{1};
            for (auto j = i + 1; j < points.size(); ++j) {
                if (points[i] == points[j]) {
                    ++identicalPoints;
                } else {
                    auto slope = calcSlope(points[i], points[j]);
                    ++slopeCounts[slope];
                }
            }
            maxCollinearPoints = std::max(maxCollinearPoints, identicalPoints);
            for (const auto [slope, count] : slopeCounts) {
                maxCollinearPoints = std::max(maxCollinearPoints, count + identicalPoints);
            }
        }
        return maxCollinearPoints;
    }
};