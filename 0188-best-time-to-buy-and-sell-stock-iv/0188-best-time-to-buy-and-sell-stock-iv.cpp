class Solution {
 public:
  int maxProfit(int k, std::vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    }
    if (k >= prices.size() / 2) {
      int profit = 0;
      for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
          profit += prices[i] - prices[i - 1];
        }
      }
      return profit;
    }
    std::vector<int> buy(k + 1, std::numeric_limits<int>::min());
    std::vector<int> sell(k + 1, 0);
    for (const auto price: prices) {
      for (int j = 1; j < k+1; ++j) {
        buy[j] = std::max(buy[j], sell[j - 1] - price);
        sell[j] = std::max(sell[j], buy[j] + price);
      }
    }
    return sell[k];
  }
};