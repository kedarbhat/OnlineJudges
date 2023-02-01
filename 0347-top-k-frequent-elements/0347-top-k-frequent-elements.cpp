class Solution {
    static auto toCounter(const std::vector<int>& nums) noexcept {
        std::unordered_map<int, int> myCounter{};
        for (auto myNum : nums) {
            myCounter[myNum]++;
        }
        return myCounter;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        using pqT = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<>>;
         pqT myPq{};
         for (const auto& [myNum, myCount] : toCounter(nums)) {
             myPq.push(std::make_pair(myCount, myNum));
         };
        std::vector<int> myResult{};
        while (myResult.size() < k) {
            const auto [myCount, myNum] = myPq.top();
            myPq.pop();
            myResult.push_back(myNum);
        }
        return myResult;
    }
};