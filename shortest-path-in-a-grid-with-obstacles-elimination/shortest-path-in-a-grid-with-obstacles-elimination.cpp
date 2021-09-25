class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int M = grid.size(), N = grid[0].size(), steps = 0;
        const vector<int> dir{-1, 0, 1, 0, -1};
        vector<vector<vector<int>>> seen(M, vector<vector<int>>(N, vector<int>(k + 1)));
        queue<vector<int>> q{{{0, 0, 0}}};
        while (!q.empty())
        {
            int sz = q.size();
            while (sz-- > 0)
            {
                auto p = q.front();
                q.pop();
                if (p[0] == M - 1 && p[1] == N - 1)
                    return steps;
                for (int i = 0; i < 4; i++)
                {
                    int x = p[0] + dir[i], y = p[1] + dir[i + 1];
                    if (x < 0 || x >= M || y < 0 || y >= N)
                        continue;
                    int w = grid[x][y] + p[2];
                    if (w > k || seen[x][y][w])
                        continue;
                    seen[x][y][w] = 1;
                    q.push({x, y, w});
                }
            }
            steps++;
        }
        return -1;
    }
};