class Solution
{
public:
    vector<string> ans;
    string buf;
    long t;
    int last;

    vector<string> addOperators(string num, int target)
    {
        buf.resize(20);
        t = target;
        last = num.size() - 1;
        dfs(num, 0, 0, 0, 0, '+');
        return ans;
    }

    void dfs(string &num, int i, int j, long sum, long sumtmp, char prevop)
    {
        long v = 0;

        for (int k = i;; k++)
        {
            v *= 10;
            v += long(num[k] - '0');
            buf[j] = num[k];
            j++;

            long sumtmptmp = (prevop == '*' ? sumtmp * v : (prevop == '+' ? sumtmp + v : sumtmp - v));

            if (k == last)
            {
                if (sum + sumtmptmp == t)
                    ans.push_back(buf.substr(0, j));
                return;
            }

            buf[j] = '*';
            dfs(num, k + 1, j + 1, sum, sumtmptmp, '*');
            buf[j] = '+';
            dfs(num, k + 1, j + 1, sum + sumtmptmp, 0, '+');
            buf[j] = '-';
            dfs(num, k + 1, j + 1, sum + sumtmptmp, 0, '-');

            if (!v)
                return;
        }
    }
};