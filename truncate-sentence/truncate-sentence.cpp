class Solution {
public:
    string truncateSentence(string s, int k) {
        string str, ans;
        vector<string> v;
        for (int i=0; i<=s.length(); i++){
            if (s[i] == ' ' || i == s.length()){
                v.push_back(str);
                str = "";
            }
            else{
                str += s[i];
            }
        }
        bool first = true;
        for (int i=0; i<k; i++){
            if (!first) ans += ' ';
            ans += v[i];
            first = false;
        }
        return ans;
    }
};