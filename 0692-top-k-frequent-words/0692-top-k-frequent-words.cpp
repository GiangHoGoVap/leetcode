class Solution {
    bool static compare(pair<int, string>& a, pair<int, string>& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> umap;
        for (string &s: words) {
            umap[s]++;
        }
        vector<pair<int, string>> v;
        for (auto &it: umap) {
            v.push_back(pair<int, string>{it.second, it.first});
        }
        sort(v.begin(), v.end(), compare);
        int i = 0;
        while (k--) {
            ans.push_back(v[i].second);
            ++i;
        }
        return ans;
    }
};