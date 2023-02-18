class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        std::vector<int> result;
        if (n == 1) {
            result.push_back(0);
            return result;
        }
        std::vector<std::vector<int>> graph(n);
        std::vector<int> degree(n, 0);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }   
        std::vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                leaves.push_back(i);
            }
        }
        while (n > 2) {
            n -= leaves.size();
            std::vector<int> newLeaves;
            for (auto& leaf : leaves) {
                for (auto& neighbor : graph[leaf]) {
                    --degree[neighbor];
                    if (degree[neighbor] == 1) {
                        newLeaves.push_back(neighbor);
                    }
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};