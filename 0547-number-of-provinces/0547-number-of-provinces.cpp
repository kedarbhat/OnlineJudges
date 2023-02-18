class Solution {
public:
    int findCircleNum(const std::vector<std::vector<int>>& isConnected) noexcept {
        using ssize_t = std::make_signed_t<std::size_t>;
        auto n = static_cast<ssize_t>(isConnected.size());
        std::vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    int p1 = i;
                    while (p1 != parent[p1]) {
                        p1 = parent[p1];
                    }
                    int p2 = j;
                    while (p2 != parent[p2]) {
                        p2 = parent[p2];
                    }
                    parent[p2] = p1;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                ++count;
            }
        }
        return count;
    }
};