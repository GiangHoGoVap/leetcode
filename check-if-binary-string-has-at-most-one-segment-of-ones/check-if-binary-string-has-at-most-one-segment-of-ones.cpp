class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 1;
        int ones = 0;
        if (s.length() == 1) return true;
        for (int i=0; i<s.length(); i++){
            if (s[i] == '1'){
                ones++;
            }
        }
        for (int i=0; i<s.length()-1; i++){
            if (s[i] == '1' && s[i+1] == '1'){
                cnt++;
            }
        }
        if (cnt == ones) return true;
        return false;
    }
};