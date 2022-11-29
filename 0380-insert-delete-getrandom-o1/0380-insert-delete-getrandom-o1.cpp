class RandomizedSet {
    vector<int> vec;
    unordered_map<int, int> positions;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (positions.count(val)) return false;
        vec.push_back(val);
        positions[val] = vec.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!positions.count(val)) return 0;
        int curPos = positions[val];
        positions[vec.back()] = curPos;
        swap(vec[curPos], vec.back());
        vec.pop_back();
        positions.erase(val);
        return true;
    }

    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */