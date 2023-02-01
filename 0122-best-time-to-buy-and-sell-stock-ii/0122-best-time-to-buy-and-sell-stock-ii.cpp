class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        auto lastProfit = 0;
        for (auto i = 1; i < prices.size(); ++i) {
            lastProfit = lastProfit + max(0, prices[i]-prices[i-1]);
        }
        return lastProfit;
    }
};