class Solution {
public:
    string reverseOnlyLetters(string s) {
        string res;
        int i, j=0;
        for(i=0; i<s.length(); i++)
        {
            if (isalpha(s[i]))
                res += s[i];
        }
        reverse(res.begin(), res.end());
        for(i=0; i<s.length(); i++)
        {
            if (isalpha(s[i]))
                s[i] = res[j++];
        }
        return s;
    }
};