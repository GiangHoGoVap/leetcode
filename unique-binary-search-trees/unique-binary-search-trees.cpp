class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
		dp[0] = 1;
		dp[1] = 1;
		
		for (int i = 2; i <= n; ++i) {
			int cnt = 0;
			for (int j = 0; j < i; ++j)
				cnt += dp[j] * dp[i - 1 - j];
			dp[i] = cnt;
		}

		return dp[n];
    }
};