class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mp, mp1;
        unordered_map<char, char> mp2;
        for(int i = 0; i < s.size(); i++){
            if (mp[s[i]] > 0 || mp1[t[i]] > 0){
                if (mp2[s[i]] != t[i])
                    return false;
            }
            mp[s[i]]++;
            mp1[t[i]]++;
            mp2[s[i]] = t[i];
        }
        return true;
    }
};