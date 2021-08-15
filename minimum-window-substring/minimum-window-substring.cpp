class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp;
        for (char c : t)
            mp[c]++;
        int start = 0, end = 0;
        int len = INT_MAX;
        int begin = 0;
        int counter = t.size();
        int n = s.size();
        while (end < n)
        {
            mp[s[end]]--;
            if (mp[s[end]] >= 0)
                counter--;
            end++;
            while (counter == 0)
            {
                if (end - start < len)
                {
                    len = end - start;
                    begin = start;
                }
                mp[s[start]]++;
                if (mp[s[start]] > 0)
                    counter++;

                start++;
            }
        }
        return (len == INT_MAX) ? "" : s.substr(begin, len);
    }
};