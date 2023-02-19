class DetectSquares {
public:
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        points.push_back(make_pair(x, y));
        counts[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int ans = 0;
        for (auto& p : points) {
            if (p.first == x || p.second == y || abs(p.first - x) != abs(p.second - y)) {
                continue;
            }
            ans += counts[x][p.second] * counts[p.first][y];
        }
        return ans;
    }

private:
    vector<pair<int, int>> points;
    std::array<std::array<int, 1001>, 1001> counts{};
};


/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */