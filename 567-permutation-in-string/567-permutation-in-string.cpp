class Solution
{
public:
    bool isEqual(int *a, int *b)
    {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i])
                return 0;
        return 1;
    }

    bool checkInclusion(string s2, string s1)
    {
        int hm[26], hm2[26];
        memset(hm, 0, sizeof hm);
        memset(hm2, 0, sizeof hm2);
        int n = s1.size(), k = s2.size();
        if (k > n)
            return 0;
        for (char a : s2)
            hm[a - 'a']++;
        for (int i = 0; i < k; ++i)
        {
            hm2[s1[i] - 'a']++;
        }
        if (isEqual(hm2, hm))
            return 1;
        for (int i = 0, j = k; j < n; j++, i++)
        {
            hm2[s1[i] - 'a']--;
            hm2[s1[j] - 'a']++;
            if (isEqual(hm2, hm))
                return 1;
        }
        return 0;
    }
};