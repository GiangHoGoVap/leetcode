class Solution {
public:
    string generateTheString(int n) {
        string ans;
        if (n % 2 == 0){
            for (int i=1; i<=n-1; i++){
                ans += 'a';
            }
            ans += 'b';
            return ans;
        }
        for (int i=1; i<=n; i++){
            ans += 'a';
        }
        return ans;
    }
};