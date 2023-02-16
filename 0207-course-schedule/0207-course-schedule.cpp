class Solution {
    using GraphT = std::unordered_map<int, std::unordered_set<int>>;
    enum class State {
        UNVISITED,
        VISITING,
        VISITED
    };
    GraphT theGraph;
    std::vector<State> theCourseStates;
    GraphT createGraph(const int n, const std::vector<std::vector<int>>& prereqs) noexcept {
       GraphT graph;
       for (auto i = 0; i < n; ++i) {
           graph.emplace(i, std::unordered_set<int>{});
       }
       for (const auto& prereq : prereqs) {
           auto child = prereq[0];
           auto parent = prereq[1];
           graph[parent].emplace(child);
       }
       return graph;
    }

     bool dfs(int parentIdx) noexcept {
        theCourseStates[parentIdx] = State::VISITING;
        for (auto childIdx : theGraph[parentIdx]) {
            if (theCourseStates[childIdx] == State::VISITED) {
                continue;
            }
            if (theCourseStates[childIdx] == State::VISITING || !dfs(childIdx)) {
                return false;
            }
        }
        theCourseStates[parentIdx] = State::VISITED;
        return true;
     }
     
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) noexcept {
        theGraph = createGraph(numCourses, prerequisites);
        theCourseStates = std::vector<State>(numCourses, State::UNVISITED);
        for (auto vertexIdx = 0; vertexIdx < numCourses; ++vertexIdx) {
            if (!dfs(vertexIdx)) {
                return false;
            }
        }
        return true;
    }
};