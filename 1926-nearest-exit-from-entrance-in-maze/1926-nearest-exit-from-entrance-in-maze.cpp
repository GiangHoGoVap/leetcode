class Solution {
    bool isValid(int n, int m, int row, int col){
        if (row >= 0 && row < n && col >= 0 && col < m) return true;
        return false;
    }
    
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int n = maze.size(), m = maze[0].size(), steps = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(ent[0], ent[1])); 
        maze[ent[0]][ent[1]] = '+';
        vector<vector<int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if ((x == 0 || y == 0 || x == n-1 || y == m-1)){
                    if ((x != ent[0] || y != ent[1])) return steps;
                }
                for (int k = 0; k < 4; k++) {
                    int nx = x + d[k][0];
                    int ny = y + d[k][1];
                    if (isValid(n, m, nx, ny) == true && maze[nx][ny] != '+') {
                        maze[nx][ny] = '+';
                        q.push(make_pair(nx, ny));
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};