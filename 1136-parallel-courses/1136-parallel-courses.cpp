class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        std::vector<std::vector<int>> graph(n + 1);
        std::vector<int> indegree(n + 1);
        for (const auto& relation : relations) {
            graph[relation[0]].push_back(relation[1]);
            ++indegree[relation[1]];
        }
        std::vector<int> queue;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) {
                queue.push_back(i);
            }
        }
        int count = 0;
        while (!queue.empty()) {
            ++count;
            std::vector<int> next_queue;
            for (const auto& node : queue) {
                for (const auto& next_node : graph[node]) {
                    --indegree[next_node];
                    if (indegree[next_node] == 0) {
                        next_queue.push_back(next_node);
                    }
                }
            }
            queue = std::move(next_queue);
        }
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] != 0) {
                return -1;
            }
        }
        return count;
    }
};