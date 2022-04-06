class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const long long mod = 1e9 + 7;
        vector<vector<long long>> dp(3, vector<long long>(target + 1, 0));
        for (auto x : arr) {
          if (x > target) continue;
          for (int i = target - x; i >= 0; i--) {
             dp[2][i + x] += dp[1][i]; dp[2][i + x] %= mod;
             dp[1][i + x] += dp[0][i]; dp[1][i + x] %= mod;
          }
          dp[0][x]++;
        }
        return dp[2][target];
    }
};