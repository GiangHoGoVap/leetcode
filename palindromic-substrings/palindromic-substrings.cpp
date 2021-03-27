class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int len = s.length();
        for(int i=0; i<len; i++){
            int l = i;
            int r = i;
            while(l>=0 && r<len && (s[l] == s[r])){
                count++;
                l--;
                r++;
            }
            l = i;
            r = i+1;
            while(l>=0 && r<len && (s[l] == s[r])){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};