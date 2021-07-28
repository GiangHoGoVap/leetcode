class Solution
{
public:
    vector<int> beautifulArray(int n)
    {
        vector<int> out(n);
        iota(begin(out), end(out), 1);
        sort(begin(out), end(out), [](auto &x, auto &y)
             { return -(x ^ y) & x & ~y; });
        return out;
    }
};