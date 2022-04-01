class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> v;
        for (int i=s.size()-1; i>-1; i--){
            v.push_back(s[i]);
        }
        s = v;
    }
};