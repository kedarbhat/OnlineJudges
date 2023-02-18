class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) const noexcept {
        int result = 0;
        std::vector<int> task_count(26, 0);
        for (auto task : tasks) {
            task_count[task - 'A']++;
        }
        std::sort(task_count.begin(), task_count.end());
        int max_val = task_count[25] - 1;
        int idle_slots = max_val * n;
        for (int i = 24; i >= 0 && task_count[i] > 0; i--) {
            idle_slots -= std::min(task_count[i], max_val);
        }
        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
    }        
};