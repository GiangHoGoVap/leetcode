class MyCircularQueue {
private:
    int head, tail, size, capacity;
    vector<int> q;
public:
    MyCircularQueue(int k) : head(0), tail(0), capacity(k), size(0), q(vector<int>(k, 0)) {}
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[tail++] = value;
        tail %= capacity;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : tail == 0 ? q[capacity-1]: q[tail-1];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */