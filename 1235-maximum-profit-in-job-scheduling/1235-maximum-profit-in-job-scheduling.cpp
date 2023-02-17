class Solution {
public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        int n = startTime.size();
        std::vector<std::vector<int>> jobs(n, std::vector<int>(3));
        for (int i = 0; i < n; i++) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        std::sort(jobs.begin(), jobs.end());
        std::map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur_profit = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur_profit > dp.rbegin()->second) {
                dp[job[0]] = cur_profit;
            }
        }
        return dp.rbegin()->second;  
    }
};