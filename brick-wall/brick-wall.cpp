class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        int res = wall.size(), n = wall.size();
        for (auto row : wall) {
            int curr_width = 0;
            for (int i = 0; i < row.size()-1; i++) {
                curr_width += row[i];
                res = min(res, n - (++m[curr_width]));
            }
        }
        return res;
    }
};