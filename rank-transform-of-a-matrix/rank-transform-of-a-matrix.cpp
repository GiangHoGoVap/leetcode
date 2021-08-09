class Solution
{
public:
    int rank[501][501];
    pair<int, int> par[501][501];

    pair<int, int> find(pair<int, int> a)
    {

        if (par[a.first][a.second] == a)
        {
            return a;
        }

        par[a.first][a.second] = find(par[a.first][a.second]);
        return par[a.first][a.second];
    }

    void union_(pair<int, int> a, pair<int, int> b)
    {

        a = find(a);
        b = find(b);

        if (rank[a.first][a.second] > rank[b.first][b.second])
        {
            par[b.first][b.second] = a;
            rank[a.first][a.second]++;
        }

        else
        {
            par[a.first][a.second] = b;
            rank[b.first][b.second]++;
        }
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &mat)
    {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                par[i][j] = {i, j};
                rank[i][j] = 1;
            }
        }

        for (int i = 0; i < m; i++)
        {
            map<int, pair<int, int>> mp;
            for (int j = 0; j < n; j++)
            {

                if (mp.find(mat[i][j]) != mp.end())
                {
                    union_({i, j}, mp[mat[i][j]]);
                }
                else
                {
                    mp[mat[i][j]] = {i, j};
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            map<int, pair<int, int>> mp;
            for (int i = 0; i < m; i++)
            {

                if (mp.find(mat[i][j]) != mp.end())
                {
                    union_({i, j}, mp[mat[i][j]]);
                }
                else
                {
                    mp[mat[i][j]] = {i, j};
                }
            }
        }

        vector<pair<int, int>> v[m][n];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto x = find({i, j});
                v[x.first][x.second].push_back({i, j});
            }
        }

        map<int, vector<vector<pair<int, int>>>> mpp;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j].size() == 0)
                {
                    continue;
                }
                mpp[mat[i][j]].push_back(v[i][j]);
            }
        }

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (auto a : mpp)
        {
            auto l = a.second;

            for (auto u : l)
            {
                int x = 0;

                for (auto a : u)
                {
                    x = max(x, max(row[a.first], col[a.second]) + 1);
                }

                for (auto a : u)
                {
                    ans[a.first][a.second] = x;
                    row[a.first] = x;
                    col[a.second] = x;
                }
            }
        }

        return ans;
    }
};