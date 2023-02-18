class Solution {
    using TaskT = std::pair<int, int>;
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        std::priority_queue<TaskT, std::vector<TaskT>, std::greater<>> nextTask;
        std::vector<std::array<int, 3>> mySortedTasks;
        for (auto i = 0; i < tasks.size(); ++i) {
            mySortedTasks.emplace_back(std::array<int, 3>{tasks[i][0], tasks[i][1], i});
        }
        std::sort(mySortedTasks.begin(), mySortedTasks.end());
        vector<int> result;
        auto currentTime{0LL};
        auto taskIndex{0};
        while (taskIndex < tasks.size() || !nextTask.empty()) {
            if (nextTask.empty() && currentTime < mySortedTasks[taskIndex][0]) {
                currentTime = mySortedTasks[taskIndex][0];
            }
            while (taskIndex < mySortedTasks.size() && currentTime >= mySortedTasks[taskIndex][0]) {
                nextTask.push({mySortedTasks[taskIndex][1], mySortedTasks[taskIndex][2]});
                ++taskIndex;
            }

            auto [processTime, index] = nextTask.top();
            nextTask.pop();

            // Complete this task and increment currTime.
            currentTime += processTime;
            result.push_back(index);
        }
        return result;
    }
};