class Solution
{
public:
    int solve(vector<string> &v, int low, bitset<26> bits = 0, string s = "")
    {
        if (low == v.size())
            return s.size();
        bitset<26> b{bits};
        for (auto &i : v[low])
        {
            if (b[i - 'a'] == 1)
            {
                return solve(v, low + 1, bits, s);
            }
            else
                b[i - 'a'] = 1;
        }
        return max(solve(v, low + 1, b, s + v[low]), solve(v, low + 1, bits, s));
    }
    int maxLength(vector<string> &arr)
    {
        return solve(arr, 0);
    }
};