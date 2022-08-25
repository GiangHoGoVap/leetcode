class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ans(26);
        for (auto i : ransomNote){
            ans[i-'a']++;
        }
        for (auto i : magazine){
            ans[i-'a']--;
        }
        for (int i=0; i<ans.size(); i++){
            if (ans[i] > 0) return false;
        }
        return true;
    }
};