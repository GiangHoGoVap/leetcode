class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> umap;
        for (char c : t) {
            umap[c]++;
        }
        int start = 0, end = 0, len = INT_MAX, begin = 0, counter = t.size(), n = s.size();
        while (end < n) {
            umap[s[end]]--;
            if (umap[s[end]] >= 0) counter--;
            end++;
            while (counter == 0) {
                if (end - start < len) {
                    len = end - start;
                    begin = start;
                }
                umap[s[start]]++;
                if (umap[s[start]] > 0) counter++;
                start++;
            }
        }
        return (len == INT_MAX) ? "" : s.substr(begin, len);
    }
};