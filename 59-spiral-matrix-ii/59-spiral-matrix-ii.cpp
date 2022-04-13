class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int c = 1, x = 0, y = 0, dir = 0, goal = n * n;
        while (c <= goal) {
            res[y][x] = c;
            if (!dir && (x + 1 == n || res[y][x + 1])
                || dir == 1 && (y + 1 == n || res[y + 1][x])
                || dir == 2 && (x - 1 < 0 || res[y][x - 1])
                || dir == 3 && (y - 1 < 0 || res[y - 1][x])) dir = (dir + 1) % 4;
            x += dir % 2 ? 0 : dir ? -1 : 1;
            y += dir % 2 ? dir > 2 ? -1 : 1 : 0;
            c++;
        }
        return res;
    }
};