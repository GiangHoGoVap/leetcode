class Solution {
public:
    int helper(int start, int diff,int elements){
        int ans = 0;
        for(int i = 0 ; i<elements ; i++){
            ans += start;
            start += diff;
        }
        return ans;
    }
    int minOperations(int n) {
        if (n % 2 != 0) return helper(2, 2, n/2);
        return helper(1, 2, n/2);
    }
};