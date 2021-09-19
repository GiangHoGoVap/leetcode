class Solution
{
public:
    int helper(string &s, string &t, int i, int j, int dp[1001][1001])
    {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int cnt = 0;
        for (int index = i; index < s.size(); index++)
        {
            if (s[index] == t[j])
                cnt += helper(s, t, index + 1, j + 1, dp);
        }
        return dp[i][j] = cnt;
    }

    int numDistinct(string s, string t)
    {
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return helper(s, t, 0, 0, dp);
    }
};