class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        int lastans = 0;
        sort(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++)
        {
            if (i != 0)
            {
                if (words[i] == words[i - 1])
                {
                    if (lastans == 1)
                        ans++;
                    continue;
                }
            }
            int ind = 0;
            lastans = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (words[i][ind] == s[j])
                {
                    ind++;
                    if (ind == words[i].size())
                    {
                        lastans++;
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};