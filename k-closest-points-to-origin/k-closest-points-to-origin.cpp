class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> dis, ans;
        int i = 0;
        for (auto &p : points)
        {
            int distance = p[0] * p[0] + p[1] * p[1];
            dis.push_back({distance, i});
            i++;
        }

        sort(dis.begin(), dis.end());
        i = 0;
        while (k--)
        {
            ans.push_back({points[dis[i][1]][0], points[dis[i][1]][1]});
            i++;
        }
        return ans;
    }
};