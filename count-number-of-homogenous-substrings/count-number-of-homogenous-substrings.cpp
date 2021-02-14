class Solution {
    const int MOD = 1000000007;
public:
    int countHomogenous(string s) {
        long long res = 0;
        for (int i=0; i<s.length(); ){
            int j = i;
            int a = 0;
            while (j < s.length() && s[i] == s[j]){
                j++;
                res += (++a);
            }
            res %= MOD;
            i = j;
        }
        return res;
    }
};