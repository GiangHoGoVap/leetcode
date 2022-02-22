class Solution {
public:
    int titleToNumber(string s) {
        int i = 0;
        long res = 0;
        if (s.empty()) return res;
        for (; i < s.size(); ++i){
            res = res * 26 + s[i] - 'A' + 1;
        }
        return res;
    }
};