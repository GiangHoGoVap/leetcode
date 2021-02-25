class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        int temp = abs(num);
        string ans;
        while (temp > 0){
            int remainder = temp % 7;
            ans += to_string(remainder);
            temp /= 7;
        }
        if (num < 0) ans += '-';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};