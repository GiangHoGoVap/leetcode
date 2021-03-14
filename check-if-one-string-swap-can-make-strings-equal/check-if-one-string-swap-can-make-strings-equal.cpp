class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        string temp = s1;
        if (temp == s2) return true;
        for (int i=0; i<s1.length()-1; i++){
            for (int j=i+1; j<s1.length(); j++){
                swap(temp[i], temp[j]);
                if (temp == s2) return true;
                temp = s1;
            }
        }
        return false;
    }
};