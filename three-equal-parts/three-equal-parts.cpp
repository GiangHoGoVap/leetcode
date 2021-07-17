class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &a)
    {
        int one = 0;
        int n = a.size();
        for (auto it : a)
            if (it)
                one++;
        if (one == 0)
            return vector<int>{0, n - 1};
        if (one % 3)
            return vector<int>{-1, -1};
        int k = one / 3;
        vector<int> pos;
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i])
                t++;
            if (t == 1 and a[i] == 1)
                pos.push_back(i);
            if (t == k)
                t = 0;
        }
        int st = pos[0], mid = pos[1], en = pos[2];
        while (en < n and a[st] == a[mid] and a[mid] == a[en])
            en++, st++, mid++;
        if (en == n)
            return vector<int>{st - 1, mid};
        return vector<int>{-1, -1};
    }
};