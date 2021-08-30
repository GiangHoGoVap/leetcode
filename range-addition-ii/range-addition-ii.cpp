class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = INT_MAX, y = INT_MAX;
        for (int i = 0; i < ops.size(); i++) {
            x = min(x, ops[i][0]);
            y = min(y, ops[i][1]);
        }
        if (x > m) x = m;
        if (y > n) y = n;
        if (x == INT_MAX) x = 0;
        if (y == INT_MAX) y = 0;
        return x * y;
    }
};