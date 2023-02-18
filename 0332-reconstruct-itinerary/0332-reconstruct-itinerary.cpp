class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        std::unordered_map<std::string, std::multiset<std::string>> graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        std::vector<std::string> result;
        std::function<void(const std::string&)> dfs = [&](const std::string& from) {
            while (!graph[from].empty()) {
                auto to = *graph[from].begin();
                graph[from].erase(graph[from].begin());
                dfs(to);
            }
            result.push_back(from);
        };
        dfs("JFK");
        std::reverse(result.begin(), result.end());
        return result;
    }
};