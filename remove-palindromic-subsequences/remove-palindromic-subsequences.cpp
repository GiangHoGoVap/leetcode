class Solution {
public:
    int removePalindromeSub(string s) {
        return (s > "") + (s != string(s.rbegin(), s.rend()));
    }
};