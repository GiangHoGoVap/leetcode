class Solution {
public:
    string reverseWords(string s) {
        string ans, temp;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                reverse(temp.begin(), temp.end());
                ans += temp + " ";
                temp = "";
                i++;
            }
            temp += s[i];
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};