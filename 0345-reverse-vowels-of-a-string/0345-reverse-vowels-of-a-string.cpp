class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int str = 0, end = n-1;

        map<char,int> vow;
        vow['a'] = 1, vow['e'] = 1, vow['o'] = 1, vow['i'] = 1, vow['u'] = 1;

        while (str < end) {
            if (vow[tolower(s[end])] == 1 && vow[tolower(s[str])] == 1) {
                swap(s[str], s[end]);
                str++;
                end--;
                continue;
            }

            if (vow[tolower(s[str])] == 0) str++;
            if (vow[tolower(s[end])] == 0) end--;
        }

        return s;
    }
};