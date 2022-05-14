struct Node {
    Node(int n, int t): node(n), time(t) {}
    int node;
    int time;
};

struct Cmp {
  bool operator() (const Node& a, const Node& b) {
      return a.time > b.time;
  }  
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<Node>> adj(N+1);
        vector<int> arrivalTime(N+1, INT32_MAX);
        vector<bool> visited(N+1, false);
        arrivalTime[K] = 0;
        
        priority_queue<Node, vector<Node>, Cmp> q;
        for(const auto &v: times)
            adj[v[0]].emplace_back(v[1], v[2]);
        
        q.emplace(K, 0);
        int max_ = 0, count = 0;
        while(!q.empty()) {
            Node cur = q.top(); q.pop();
            if(visited[cur.node]) continue;
            visited[cur.node] = true;
            ++count;
            max_ = max(arrivalTime[cur.node], max_);
            for(const auto &n: adj[cur.node]) {
                int newT = arrivalTime[cur.node]+n.time;
                if(newT < arrivalTime[n.node]) {
                    arrivalTime[n.node] = newT;
                    q.emplace(n.node, newT);
                }
            }   
        }

        return count == N ? max_ : -1;
    }
};