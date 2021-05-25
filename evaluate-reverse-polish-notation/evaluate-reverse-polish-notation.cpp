class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int a, b, res;
        for (int i = 0; i < tokens.size(); i++) {
            try { 
                s.push(stoi(tokens[i])); 
            } 
            catch (exception e) {
                b = s.top(); s.pop();
                a = s.top(); s.pop();
                char op = tokens[i][0];
                res = op == '+' ? a + b : op == '-' ? a - b : op == '*' ? a * b : a / b;
                s.push(res);
            }
        }
        return s.top();
    }
};