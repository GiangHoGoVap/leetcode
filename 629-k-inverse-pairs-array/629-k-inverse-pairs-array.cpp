class Solution
{
public:
	int kInversePairs(int n, int k)
	{
		int bigM = 1e9 + 7, dp[1001][1001], maxr = 0;
		for (int i = 1; i <= n; ++i)
		{
			dp[i][0] = 1;
		};
		for (int i = 2; i <= n; ++i)
		{
			maxr += (i - 1);
			for (int j = 1; j <= min(k, maxr); ++j)
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % bigM;
				if (j >= i)
				{
					dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + bigM) % bigM;
				}
			}
		}
		return dp[n][k];
	}
};