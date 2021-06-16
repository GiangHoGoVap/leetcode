class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<helper> s;
        s.push({"", n, 0});
        while (!s.empty()) {
            helper h = s.top();
            s.pop();
            if(h.leftpairs == 0 && h.remaining == 0) {
                result.push_back(h.s);
                continue;
            }
            
            if (h.leftpairs > 0) {
                s.push({h.s + "(", h.leftpairs-1, h.remaining+1});
                
            } 
            if (h.remaining > 0) {
                s.push({h.s + ")", h.leftpairs, h.remaining-1});
            }
        }
        return result;
    }
    
private:
    struct helper {
        string s;
        int leftpairs;
        int remaining;
    };
};