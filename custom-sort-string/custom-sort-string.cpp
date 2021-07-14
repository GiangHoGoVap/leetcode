class Solution {
public:
    string customSortString(string order, string str) {
        int chars[128];
        for (int i = 0, lmt = order.size(); i < lmt; i++) {
            chars[order[i]] = i;
        }
        sort(begin(str), end(str), [&chars](char a, char b){return chars[a] < chars[b];});
        return str;
    }
};