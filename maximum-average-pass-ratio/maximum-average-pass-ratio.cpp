typedef pair<double, double> pdd;

struct cmp {
    bool operator() (pdd &a, pdd &b) {
        return (a.first + 1.0) / (a.second + 1.0) - (a.first) / (a.second) < (b.first + 1.0) / (b.second + 1.0) - (b.first) / (b.second);
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pdd, vector<pdd>, cmp> q;
        for(auto &i : classes) {
            q.push({i[0], i[1]});
        }
        for(int i = 0; i < extraStudents; i++) {
            pdd c = q.top();
            q.pop();
            c.first++;
            c.second++;
            q.push(c);
        }
        int n = classes.size();
        double res = 0;
        while(!q.empty()) {
            pdd d = q.top();
            q.pop();
            res += d.first / d.second;
        }
        return res / (double)n;
    }
};