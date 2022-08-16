class Solution {
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> letter;
        for (int i = 0; i < s.size(); ++i) {
            ++letter[s[i]];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (letter[s[i]] == 1) return i;
        }
        return -1;
    }
};