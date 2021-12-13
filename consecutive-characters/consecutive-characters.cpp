class Solution {
public:
    int maxPower(string s) {
        int counter = 1;
        int m = 1;
        for (int i=1; i<s.length(); i++){
            if (s[i] == s[i-1]){
                counter++;
                m = max(m, counter);
            }
            else counter = 1;
        }
        return m;
    }
};