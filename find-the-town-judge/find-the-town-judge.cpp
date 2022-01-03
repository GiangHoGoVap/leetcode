class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        if (N == 1)
            return 1;

        map<int, pair<int, int>> mp;
        map<int, pair<int, int>>::iterator itr;

        for (int i = 0; i < trust.size(); i++)
        {
            mp[trust[i][0]].first++;
            mp[trust[i][1]].second++;
        }

        for (itr = mp.begin(); itr != mp.end(); itr++)
        {
            if (itr->second.first == 0 && itr->second.second == N - 1)
                return itr->first;
        }

        return -1;
    }
};