class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
		if (grid[0][0] || grid[n-1][n-1]) return -1;
		if (n==1) return 1;
		vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
		vector<vector<int>> dp(n,vector<int>(n,0));
		queue<pair<int,int>> q;
		q.push({0,0});
		dp[0][0] = 1;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (auto v : dir){
				int a = x+v[0];
				int b = y+v[1];
				if (a<0 || b<0 || a>=n || b>=n || dp[a][b] || grid[a][b]) continue;
				dp[a][b] = dp[x][y]+1;
				q.push({a,b});
				if (a==n-1 && b==n-1) return dp[a][b];
			}
		}
		return -1;
    }
};