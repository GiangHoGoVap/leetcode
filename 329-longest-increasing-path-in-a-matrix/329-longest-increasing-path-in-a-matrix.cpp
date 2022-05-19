class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp,int pre){
        if (i<0 || j<0 || i>=v.size() || j>=v[0].size() || v[i][j]<=pre) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int a = 1 + dfs(i+1,j,v,dp,v[i][j]);
        int b =  1 + dfs(i-1,j,v,dp,v[i][j]);
        int c = 1 + dfs(i,j+1,v,dp,v[i][j]);
        int d =  1 + dfs(i,j-1,v,dp,v[i][j]);
        dp[i][j] = max(a,max(b,max(c,d)));
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& v) {
        if (v.size()==0) return 0;
        vector<vector<int>>dp(v.size(),vector<int>(v[0].size(),-1));
        int maxi=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(dp[i][j] == -1)
                    maxi = max(maxi,dfs(i,j,v,dp,INT_MIN));
            }
        }
        return maxi;
    }
};