class NumMatrix {
private:
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        v.assign(matrix.size() ,vector<int>(matrix[0].size()+1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                v[i][j+1] = v[i][j] + matrix[i][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <= row2; i++) {
            res += v[i][col2+1] - v[i][col1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */