class Solution {
private:
 std::vector<std::unordered_set<int>> graph;
 std::vector<bool> visited;
    bool dfs(int source, int destination) noexcept {
        if (visited[source]) {
            return false;
        }
        if (graph[source].empty()) {
            return source == destination;
        }
        visited[source] = true;
        for (const auto& next : graph[source]) {
            if (!dfs(next, destination)) {
                return false;
            }
        }
        visited[source] = false;
        return true;
    }
 public:
    bool leadsToDestination(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        if (edges.empty()) {
            return source == destination;
        }
        graph.resize(n);
        visited.resize(n, false);
        for (const auto& edge : edges) {
            graph[edge[0]].emplace(edge[1]);
        }
        if (std::count_if(graph.cbegin(), graph.cend(), [=](const auto& aSet) { return aSet.find(destination) != aSet.cend(); })+1 == n) {
            return true;
        }
        return dfs(source, destination);
    }
};