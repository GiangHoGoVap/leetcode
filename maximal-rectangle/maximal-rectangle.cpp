class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        if (n + m == 1)
            return matrix.front().front() == '1';
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i - 1][j - 1] != '0')
                    dp[i][j] = 1 + dp[i][j - 1];
            }
        }
        int area = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int width = dp[i][j];
                int k = i - 1;
                int height = 1;
                area = max(area, width * height);
                while (k > 0 and dp[k][j] > 0)
                {
                    height++;
                    width = min(width, dp[k--][j]);
                    area = max(width * height, area);
                }
            }
        }
        return area;
    }
};