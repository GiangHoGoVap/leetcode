class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        vector<vector<int>> ans;
        set<pair<int,int>> s;
        for (auto x: buildings) {
            s.insert({x[0], -x[2]});
            s.insert({x[1], x[2]});
        }
        multiset<int> mp;
        mp.insert(0);
        for (auto x: s) {
            int prev = *mp.rbegin();
            if (x.second < 0) mp.insert(-x.second);
            else mp.erase(mp.lower_bound(x.second));
            int nw = *mp.rbegin();
            if (prev != nw) ans.push_back({x.first,nw});
        }
        return ans;
    }
};