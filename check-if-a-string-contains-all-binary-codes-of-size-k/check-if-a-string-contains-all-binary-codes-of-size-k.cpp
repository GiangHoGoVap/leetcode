class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> ans;
        int len = s.length();
        if (len-k+1 < pow(2,k)) return false;
        else{
            for(int i=0; i<=len-k; i++){
                string w = "";
                for(int j=i; j<i+k; j++){
                    w += s[j];
                }
                ans.insert(w);
            }
            if (ans.size() == pow(2,k)) return true;
        }
        return false;
    }
};