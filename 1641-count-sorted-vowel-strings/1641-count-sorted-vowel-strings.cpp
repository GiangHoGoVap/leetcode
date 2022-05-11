class Solution {
    int count;
    void solve(int &n, int index = 1, int len = 0){
        if(len == n)
            count++;
        else
            for(int i = index; i <= 5; i++)
                solve(n, i, len + 1);
    }
public:
    int countVowelStrings(int n) {
        count = 0;
        solve(n);
        return count;
    }
};