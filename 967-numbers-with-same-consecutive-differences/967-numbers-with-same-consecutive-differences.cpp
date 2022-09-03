class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        queue<int> q;
        vector<int> ans;
        for (int i=1; i<=9; i++) {
            q.push(i);
        }
        q.push(-1);
        int cnt = 1;
        while (!q.empty() && cnt < N) {  
            int t = q.front();
            if (t == -1) {
                q.pop();
                cnt++;
                q.push(-1);
                continue;
            }
            for (int i=0; i<=9; i++) {
                if (abs(t % 10 - i) == K) q.push(t * 10 + i);
            }
            q.pop();
        }
        while (!q.empty()) {
           int t = q.front();
            if (t != -1) ans.push_back(t);
            q.pop();
        }
        if (N == 1) ans.push_back(0);
        return ans;
    }
};