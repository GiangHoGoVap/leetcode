class Solution {
public:
    char flip(char c){
        return (c == '0') ? '1' : '0';
    }
    int solve(string str, char expected){
        int flipCount = 0;
        for (int i=0; i<str.length(); i++){
            if (str[i] != expected) flipCount++;
            expected = flip(expected);
        }
        return flipCount;
    }
    int minOperations(string s) {
        return min(solve(s, '0'), solve(s, '1'));
    }
};