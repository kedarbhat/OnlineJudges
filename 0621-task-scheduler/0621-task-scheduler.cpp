class Solution {
public:
    int leastInterval(const std::vector<char>& tasks, int n) const noexcept {
        int result = 0;
        std::array<int, 26> taskCount{};
        for (auto task : tasks) {
            ++taskCount[task - 'A'];
        }
        std::sort(taskCount.begin(), taskCount.end());
        int maxVal = taskCount[25] - 1;
        int idleSlots = maxVal * n;
        for (int i = 24; i >= 0 && taskCount[i] > 0; --i) {
            idleSlots -= std::min(taskCount[i], maxVal);
        }
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }        
};