class MyStack {
public:
    queue<int> q;
    queue<int> helper;
    MyStack() {}
    
    void push(int x) {
        while (!q.empty()){
            int front = q.front();
            q.pop();
            helper.push(front);
        }
        q.push(x);
        while (!helper.empty()){
            int front = helper.front();
            helper.pop();
            q.push(front);
        }
    }
    
    int pop() {
        if (q.size() == 0){
            return -1;
        }
        int front = q.front();
        q.pop();
        return front;
    }
    
    int top() {
        if (q.size() == 0){
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        if (q.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */