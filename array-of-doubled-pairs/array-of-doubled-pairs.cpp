class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        map<int, int> mp;
        map<int, int, greater<int>> mn;
        int zeros = 0;
        for (auto &x : arr)
            if (x > 0)
                mp[x]++;
            else if (x < 0)
                mn[x]++;
            else
                zeros++;

        if (zeros % 2 == 1)
            return false;

        for (auto &it : mn)
            if (it.second)
            {
                int new_x = it.first * 2;
                if (!mn.count(new_x))
                    return false;
                mn[new_x] -= it.second;
                if (mn[new_x] < 0)
                    return false;
            }

        for (auto &it : mp)
            if (it.second)
            {
                int new_x = it.first * 2;
                if (!mp.count(new_x))
                    return false;
                mp[new_x] -= it.second;
                if (mp[new_x] < 0)
                    return false;
            }

        return true;
    }
};