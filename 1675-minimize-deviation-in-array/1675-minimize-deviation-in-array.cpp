class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int x = INT_MAX, res;
        priority_queue<int> pq;
        
        for (auto& n:nums) {
            if (n&1) {
                pq.push(n*2);
                x = min(x, n*2);
            } else {
                pq.push(n);
                x = min(x, n);
            }
        }
        
        res = pq.top() - x;
        while (!(pq.top()&1)) {
            int temp  = pq.top()/2; pq.pop();
            x = min(x, temp);
            pq.push(temp);
            res = min(res, pq.top() - x);
        }
        
        return res;
    }
};