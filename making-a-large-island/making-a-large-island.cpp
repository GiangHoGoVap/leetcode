class Solution
{
public:
    int n, m, area, answer = 0, res, unique_color = 11;
    map<int, int> color_area;
    vector<int> move = {-1, 0, 1, 0, -1};
    void findarea(vector<vector<int>> &grid, int i, int j, int &unique_color)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1)
            return;
        ++area;
        grid[i][j] = unique_color;
        for (int k = 0; k < 4; k++)
            findarea(grid, i + move[k], j + move[k + 1], unique_color);
        return;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();
        int quit = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    ++quit;

        if (quit == n * m)
            return quit;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    area = 0;
                    ++unique_color;
                    findarea(grid, i, j, unique_color);
                    color_area[unique_color] = area;
                }
            }
        }

        vector<int> f(4);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int pqr = 0; pqr < 4; pqr++)
                    f[pqr] = -101;
                if (grid[i][j] == 0)
                {
                    if (i > 0 && grid[i - 1][j] != 0)
                    {
                        f[0] = grid[i - 1][j];
                    }
                    if (j > 0 && grid[i][j - 1] != 0)
                    {
                        if (f[0] && grid[i][j - 1] == f[0])
                            ;
                        else
                            f[1] = grid[i][j - 1];
                    }
                    if (i < n - 1 && grid[i + 1][j] != 0)
                    {
                        if ((f[0] || f[1]) && (grid[i + 1][j] == f[0] || grid[i + 1][j] == f[1]))
                            ;
                        else
                            f[2] = grid[i + 1][j];
                    }
                    if (j < m - 1 && grid[i][j + 1] != 0)
                    {
                        if ((f[0] || f[1] || f[2]) && (grid[i][j + 1] == f[0]) || (grid[i][j + 1] == f[1]) || (grid[i][j + 1] == f[2]))
                            ;
                        else
                            f[3] = grid[i][j + 1];
                    }
                }
                res = 1;
                for (int i = 0; i < 4; i++)
                    if (f[i] != -101)
                        res += color_area[f[i]];
                answer = max(res, answer);
            }
        }
        return answer;
    }
};