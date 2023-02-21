class Solution {
 public:
  int numWays(int n, int k) {
    switch (n) {
      case 0:
        return 0;
      case 1:
        return k;
      case 2:
        return k * k;
      default:
        break;
    }
    int dp[n];
    dp[0] = k;
    dp[1] = k * k;
    for (int i = 2; i < n; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n - 1];
  }
};