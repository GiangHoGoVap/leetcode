class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (!k || len < 2) return 0;
        k = min(k * 2, len - len % 2);
        int dp[k];
        for (int i = 0; i < k; i++) 
            dp[i] = i % 2 ? 0 : INT_MAX;
        for (int currPrice: prices) {
            dp[0] = min(dp[0], currPrice);
            for (int i = 1; i < k; i++) {
                dp[i] = i % 2 ? max(dp[i], currPrice - dp[i - 1]) : min(dp[i], currPrice - dp[i - 1]);
            }
        }
        return dp[k - 1];
    }
};