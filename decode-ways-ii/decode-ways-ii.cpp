class Solution
{
public:
    int numDecodings(string s)
    {
        long long int n = s.size(), i, p = 1000000007;
        vector<long long int> dp(2, 1);
        dp[n % 2] = 1;
        if (s[n - 1] == '0')
            dp[(n - 1) % 2] = 0;
        else if (s[n - 1] == '*')
            dp[(n - 1) % 2] = 9;

        for (i = n - 2; i >= 0; i--)
        {
            long long int temp = 0;

            if (s[i] == '*')
                temp += 9 * (dp[(i + 1) % 2] % p);
            else if (s[i] != '0')
                temp += (dp[(i + 1) % 2] % p);

            if ((s[i] == '1' && s[i + 1] != '*') || (s[i] == '2' && s[i + 1] != '*' && s[i + 1] <= '6') || (s[i] == '*' && s[i + 1] != '*' && s[i + 1] > '6'))
                temp += dp[(i + 2) % 2] % p;

            else if (s[i] == '1' && s[i + 1] == '*')
                temp += 9 * (dp[(i + 2) % 2] % p);

            else if (s[i] == '2' && s[i + 1] == '*')
                temp += 6 * (dp[(i + 2) % 2] % p);

            else if (s[i] == '*' && s[i + 1] == '*')
                temp += 15 * (dp[(i + 2) % 2] % p);

            else if (s[i] == '*' && s[i + 1] <= '6')
                temp += 2 * (dp[(i + 2) % 2] % p);

            dp[i % 2] = temp % p;
        }
        return dp[0];
    }
};
