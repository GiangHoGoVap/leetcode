class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>& t = obstacleGrid;
        int row = t.size(), col = t[0].size();
        vector<vector<long>> dp(row, vector<long>(col, 0));
        dp[0][0] = (t[0][0] == 1 ? 0 : 1);
        for (int i = 1; i < row; ++i){ 
            dp[i][0] = (t[i][0] == 0 && dp[i - 1][0] > 0 ? 1 : 0);
        }
        for (int i = 1; i < col; i++){
            dp[0][i] = (t[0][i] == 0 && dp[0][i - 1] > 0 ? 1 : 0);
        }
        for (int i = 1; i < row; ++i){
            for (int j = 1; j < col; ++j){ 
                dp[i][j] = (t[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1]); 
            }
        }
        return dp[row - 1][col - 1];  
    }
};