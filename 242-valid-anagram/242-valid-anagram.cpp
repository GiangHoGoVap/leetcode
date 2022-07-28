class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> temp1(26, 0), temp2(26, 0);
        for (char c : s){
            temp1[c - 'a']++;
        }
        for (char c : t){
            temp2[c - 'a']++;
        }
        for (int i=0; i<26; i++){
            if (temp1[i] != temp2[i]) return false;
        }
        return true;
    }
};