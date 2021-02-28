class FreqStack {
    priority_queue<vector<int>> pq;
    unordered_map<int, int> map;
    int id = 0;
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        ++map[x];
        pq.push({map[x], id++, x});
    }
    
    int pop() {
        auto p = pq.top();
        pq.pop();
        --map[p[2]];
        return p[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */