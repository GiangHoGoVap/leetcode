class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        const int nx[] = {0, 1, 0, -1};
        const int ny[] = {1, 0, -1, 0};
        int x = 0, y = -1;
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        while (m > 0 && n > 0){
            int k;
            if (i % 2 == 0){
                k = n;
                m--;
            }
            else{
                k = m; 
                n--;
            }
            while (k--){
                x += nx[i];
                y += ny[i];
                res.push_back(matrix[x][y]);
            }
            i = (i + 1) % 4;
        }
        return res;
    }
};