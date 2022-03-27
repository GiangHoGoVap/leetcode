class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        for (int i=0; i<s.length(); i++){
            if ((s[i] != ' ' && s[i+1] == ' ') ||  (s[i] != ' ' && s[i+1] == NULL)){
                ans++;
            }
        }
        return ans;
    }
};