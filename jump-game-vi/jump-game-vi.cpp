class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int N = nums.size();
        int dp[N+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        multiset<int> maxValue;
        maxValue.insert(dp[0]);
        for (int i = 1; i < N; i++) {
            dp[i] = nums[i] + *maxValue.rbegin();
            maxValue.insert(dp[i]);
            if (i >= k) {
                maxValue.erase(maxValue.find(dp[i-k]));
            }
        }
        return dp[N-1];
    }
};