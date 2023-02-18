class Solution {
    int findRoot(std::vector<int>& parent, int i) noexcept {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
public:
    int countComponents(int n, const std::vector<std::vector<int>>& edges) noexcept {
        std::vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (const auto& edge : edges) {
            int root_a = findRoot(parent, edge[0]);
            int root_b = findRoot(parent, edge[1]);
            if (root_a != root_b) {
                parent[root_a] = root_b;
                --n;
            }
        }
        return n;
    }
};