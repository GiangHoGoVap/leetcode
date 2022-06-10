class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char,bool> um;
        int low = 0, max_len = 0;
        for(int high = 0; high < len; high++){
            while(um[s[high]] == true){
                um[s[low++]] = false;
            }
            um[s[high]] = true;
            if(high - low + 1 > max_len)
                max_len = high - low + 1;
        }
        return max_len;
    }
};