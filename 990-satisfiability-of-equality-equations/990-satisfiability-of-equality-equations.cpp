class Solution {
    vector<int> equal;
    int find_eql(int v) {
        if (v == equal[v]) return v;
        return equal[v] = find_eql(equal[v]);
    }
    
    void union_eql(int a, int b) {
        a = find_eql(a);
        b = find_eql(b);
        if (a == b) return;
        equal[b] = a;
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) {
            equal.push_back(i);
        }
        for (string &str : equations) {
            if (str[1] == '!' || str[0] == str[3]) continue;
            union_eql(str[0]-'a', str[3]-'a');
        }
        for (string &str : equations) {
            if (str[1] == '!') {
                int x = find_eql(str[0] - 'a');
                int y = find_eql(str[3] - 'a');
                if (x == y) return false;
            }
        }
        return true;
    }
};