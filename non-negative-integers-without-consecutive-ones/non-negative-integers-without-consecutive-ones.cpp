class Solution
{
public:
    int findIntegers(int n)
    {
        vector<vector<int>> t(2, vector<int>(32));
        t[0][0] = 1;
        for (int len = 1; len < 32; len++)
        {
            t[0][len] = t[0][len - 1] + t[1][len - 1];
            t[1][len] = t[0][len - 1];
        }
        bitset<32> bt(n);
        string str = bt.to_string();
        int result = 0;
        int prevBit = -1;
        bool consOne = false;
        for (int i = str.length() - 1; i >= 0; i--)
        {
            int lastBit = ((n >> i) & 1);

            if (lastBit == 1)
            {
                result += t[0][i + 1];
                if (prevBit == 1)
                {
                    consOne = true;
                    break;
                }
            }
            prevBit = lastBit;
        }
        if (!consOne)
            result++;
        return result;
    }
};