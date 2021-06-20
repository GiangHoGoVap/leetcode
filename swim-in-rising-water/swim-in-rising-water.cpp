class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int ans = 0;
        int N = grid.size();
        bool vis[N*N+1];
        for(int i = 0; i <= N*N; i++) vis[i] = false;
        int r[] = {1,-1,0,0};
        int c[] = {0,0,1,-1};
        priority_queue< pair<int, int> >pq;
        pq.push({-grid[0][0], 0});
        while(!pq.empty()) {
            pair<int, int> t = pq.top();
            pq.pop();
            int i = t.second/N;
            int j = t.second%N;
            ans = max(ans, grid[i][j]);
            if(i == N-1 && j == N-1) break;
            for(int k = 0; k < 4; k++) {
                int ni = i + r[k];
                int nj = j + c[k];
                if(ni >= 0 && ni < N && nj >= 0 && nj < N && !vis[ni*N + nj]) {
                    vis[ni*N + nj] = true;
                    pq.push({-grid[ni][nj], ni*N + nj});
                }
            }
        }
        return ans;
    }
};