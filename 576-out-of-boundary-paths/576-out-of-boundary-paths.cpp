class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dp[51][51][51];
    int mod = 1e9 + 7;
    long long int dfs(int m, int n, int maxx, int x, int y)
    {
        int i;
        if (maxx <= 0)
            return 0;
        if (dp[x][y][maxx] != -1)
            return dp[x][y][maxx];
        long long int ways = 0;
        for (i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < 0 || X >= m || Y < 0 || Y >= n)
            {
                ways++;
                continue;
            }
            ways += dfs(m, n, maxx - 1, X, Y) % mod;
        }
        return dp[x][y][maxx] = ways % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        long long int h = dfs(m, n, maxMove, startRow, startColumn) % mod;
        return h;
    }
};