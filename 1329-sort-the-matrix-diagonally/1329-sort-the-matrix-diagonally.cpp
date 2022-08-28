class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int x, y;
        
        for(int i = 0; i < c; i++) {
            vector<int> temp;
            x = i;
            y = 0;
            while(x < c && y < r) {
                temp.push_back(mat[y][x]);
                x++;
                y++;
            }
            sort(temp.begin(), temp.end());
            x = i;
            y = 0;
            int j = 0;
            while(x < c && y < r) {
                mat[y][x] = temp[j];
                x++;
                y++;
                j++;
            }
        }
        
        for(int i = 1; i < r; i++) {
            vector<int> temp;
            x = 0;
            y = i;
            while(x < c && y < r) {
                temp.push_back(mat[y][x]);
                x++;
                y++;
            }
            sort(temp.begin(), temp.end());
            x = 0;
            y = i;
            int j = 0;
            while(x < c && y < r) {
                mat[y][x] = temp[j];
                x++;
                y++;
                j++;
            }
        }
        return mat;
    }
};