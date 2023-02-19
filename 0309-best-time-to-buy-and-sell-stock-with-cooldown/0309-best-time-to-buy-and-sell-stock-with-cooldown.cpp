class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int buy = -prices[0];
        int sell = 0;
        int prev_sell = 0;
        int prev_buy;
        for (int i = 1; i < n; i++) {
            prev_buy = buy;
            buy = std::max(prev_sell - prices[i], buy);
            prev_sell = sell;
            sell = std::max(prev_buy + prices[i], sell);
        }
        return sell;
    }
};