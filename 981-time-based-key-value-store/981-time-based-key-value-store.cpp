class TimeMap {
public:
    map<string, pair<vector<int>, vector<string>>> M;
    
    TimeMap() {
        M = {};
    }
    
    void set(string key, string value, int timestamp) {
        if (M.find(key) != M.end()) {
            M[key].first.push_back(timestamp);
            M[key].second.push_back(value);
        }
        else {
            M[key] = {{timestamp},{value}};
        }
    }
    
    string get(string key, int timestamp) {
        if (M.find(key) == M.end()) return "";
        auto itr = std::lower_bound(M[key].first.begin(), M[key].first.end(), timestamp);
        int dist = std::distance(M[key].first.begin(), itr);
        if (dist == 0 && M[key].first[dist] > timestamp) return "";
        if (dist >= M[key].first.size()) return M[key].second[M[key].first.size() - 1];
        if (M[key].first[dist] == timestamp) return M[key].second[dist];
        return M[key].second[dist - 1];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */