class Solution {
    int pos = 0;
public:
    int calculate(string& s) {
        char op = '+';
        int ret = 0;
        int operand = 0;
        while (pos < s.size())
        {
            if (isdigit(s[pos]))
            {
                operand = operand*10 - '0' + s[pos++];
            } 
            else if (s[pos] == '+' || s[pos] == '-')
            {
                if (op == '+') ret += operand;
                else ret -= operand;
                operand = 0;
                op = s[pos] == '+'? '+' : '-';
                pos ++;
            }
            else if (s[pos] == '(')
            {
                pos++;
                operand = calculate(s);
                    
            }
            else if (s[pos] == ')')
            {
                if (op == '+') ret += operand;
                else ret -= operand;                
                pos++;
                return ret;
            }
            else
            {
                pos ++;
            }     
        }
        
        if (op == '+') ret += operand;
        else ret -= operand;
        return ret;
    }
};