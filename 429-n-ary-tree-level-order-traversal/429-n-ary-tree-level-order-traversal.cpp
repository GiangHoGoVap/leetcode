/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if (!root)
            return res;
        q.push(root);
        while (!q.empty()) {
            vector<int> a;
            int l = q.size();
            for (int i=0; i<l; i++){
                Node* t = q.front();
                q.pop();
                a.push_back(t->val);
                vector<Node*> c = t->children;
                for (int j=0; j<c.size(); j++) {
                    q.push(c[j]);
                }
            }
            res.push_back(a);
        }
        return res;
    }
};