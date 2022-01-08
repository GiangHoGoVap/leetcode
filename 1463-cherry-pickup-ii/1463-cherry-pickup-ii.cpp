class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int height = grid.size();
        int width = grid[0].size();
        int dp[70][70][2];
        int i, j;
        int round = 1;
        for (i = 0; i < width; i++)
            for (j = 0; j < width; j++)
                dp[i][j][0] = INT_MIN;
        dp[0][width - 1][0] = grid[0][0] + grid[0][width - 1];
        while (round < height)
        {
            int id = round & 1;
            for (i = 0; i < width; i++)
            {
                for (j = 0; j < width - 1; j++)
                    dp[i][j][id ^ 1] = max(dp[i][j][id ^ 1], dp[i][j + 1][id ^ 1]);
                for (j = width - 1; j > 0; j--)
                    dp[i][j][id ^ 1] = max(dp[i][j][id ^ 1], dp[i][j - 1][id ^ 1]);
            }
            for (j = 0; j < width; j++)
            {
                for (i = 0; i < width - 1; i++)
                    dp[i][j][id ^ 1] = max(dp[i][j][id ^ 1], dp[i + 1][j][id ^ 1]);
                for (i = width - 1; i > 0; i--)
                    dp[i][j][id ^ 1] = max(dp[i][j][id ^ 1], dp[i - 1][j][id ^ 1]);
            }
            for (i = 0; i < width; i++)
                for (j = 0; j < width; j++)
                {
                    if (i != j)
                        dp[i][j][id] = dp[i][j][id ^ 1] + grid[round][i] + grid[round][j];
                    else
                        dp[i][j][id] = dp[i][j][id ^ 1] + grid[round][i];
                }
            //
            round++;
        }
        int ans = 0;
        int id = (round + 1) & 1;
        for (i = 0; i < width; i++)
            for (j = 0; j < width; j++)
                ans = max(ans, dp[i][j][id]);
        return ans;
    }
};