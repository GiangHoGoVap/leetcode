class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int temp = 0;
        int size_a = a.size() - 1;
        int size_b = b.size() - 1;
        while (size_a >= 0 || size_b >= 0 || temp == 1){
            temp += ((size_a >= 0) ? a[size_a] - '0': 0);
            temp += ((size_b >= 0) ? b[size_b] - '0': 0);
            ans = char(temp % 2 + '0') + ans;
            temp /= 2;
            size_a--;
            size_b--;
        }
        return ans;
    }
};