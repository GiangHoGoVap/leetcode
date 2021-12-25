class Solution {
public:
    int calculate(const string& s, int index = 0, bool negateFirst = false) {
        int num = readNum(s, index);
        if (negateFirst) num *= -1;
        while (index < s.length()) {
            while (s[index] == ' ') ++index;
            switch (s[index++]) {
                case '*': num *= readNum(s, index); break;
                case '/': num /= readNum(s, index); break;
                case '+': return num + calculate(s, index);
                case '-': return num + calculate(s, index, true);
            }
        }
        return num;
    }
    
    static int readNum(const string& s, int& index) {
        while (s[index] == ' ') ++index;
        int ans = 0;
        while (index < s.length() && s[index] >= '0' && s[index] <= '9') {
            ans *= 10;
            ans += s[index++] - '0';
        }
        return ans;
    }
};