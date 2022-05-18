class Solution
{
public:
    int time = 0;
    vector<vector<int>> ans;

    void dfs(vector<vector<int>> &g, vector<int> &times, int u, int parent, vector<bool> &vis, vector<int> &low)
    {
        vis[u] = true;
        times[u] = time++;
        low[u] = times[u];
        for (auto child : g[u])
        {
            if (child == parent)
                continue;
            if (!vis[child])
            {
                dfs(g, times, child, u, vis, low);
                low[u] = min(low[u], low[child]);
                if (low[child] > times[u])
                {
                    ans.push_back({u, child});
                }
            }
            else
            {
                low[u] = min(low[u], times[child]);
            }
        }

        return;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> g(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> times(n, 0);
        vector<int> low(n, 0);
        vector<bool> vis(n, false);
        dfs(g, times, 0, -1, vis, low);
        return ans;
    }
};