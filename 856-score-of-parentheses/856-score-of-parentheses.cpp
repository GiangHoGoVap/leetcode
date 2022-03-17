class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, balance = 0, len = S.size();
        for (int index=0; index<len; index++){
            balance += S[index] == '(' ? 1 : -1;
            if (index && S[index - 1] == '(' && S[index] == ')')
                res += pow( 2, balance );
        }
        return res;
    }
};