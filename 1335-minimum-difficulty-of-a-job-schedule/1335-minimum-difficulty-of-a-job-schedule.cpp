#define INF 1000000

class Solution {
    int dp[1005][11];
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        memset(dp, -1, sizeof dp);
        int ans = solve(jobDifficulty, 0, n, d);
        if (ans == INF) return -1;
        return ans;
    }
    
    int solve(vector<int>&a, int i, int n, int d) {
        if (i >= n) {
            if (d > 0) return INF;
            return 0;
        }
        if (d == 0) return INF;
        int ans = INF, mx = -INF, &res = dp[i][d];
        if (res != -1) return res;
        for (int j = i; j < n; j++) {
            mx = max(a[j], mx);
            ans = min(ans, mx + solve(a, j + 1, n, d - 1));
        }
        return res = ans;
    }
};