class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string res = "";
        stringstream str(s);
        stack<string> stk;

        while (str >> temp) {
            stk.push(temp);
            stk.push(" ");
        }
        
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
            res += stk.top();
            stk.pop();
        }
        
        if (res.length() == 0) 
            return "";
        return res.substr(1, res.length()-1);
    }
};