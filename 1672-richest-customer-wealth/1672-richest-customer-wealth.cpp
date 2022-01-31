class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts[0].size();
        int n = accounts.size();
        int ans = 0;
        for (int i=0; i<n; i++){
            int temp = 0;
            for (int j=0; j<m; j++){
                temp += accounts[i][j];
            }
            if (temp > ans) ans = temp;
        }
        return ans;
    }
};