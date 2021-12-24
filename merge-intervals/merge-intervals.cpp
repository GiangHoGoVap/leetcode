class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals[0].empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int> &vec1, const vector<int> &vec2) {
            if (vec1[0] < vec2[0]) {
                return true;
            }
            else if(vec1[0] == vec2[0]) {
                return vec1[1] < vec2[1];
            }
            else {
                return false;
            }
        });
        vector<vector<int>> res;
        vector<int> vec = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            if(max(vec[0], intervals[i][0]) <= min(vec[1], intervals[i][1])) {
                vec[0] = min(vec[0], intervals[i][0]);
                vec[1] = max(vec[1], intervals[i][1]);
            }
            else {
                res.push_back(vec);
                vec = intervals[i];
            }
        }
        res.push_back(vec);
        return res;
    }
};