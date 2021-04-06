class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1, v2;
        istringstream ss(sentence1);
        string str1;
        while (ss >> str1){
            v1.push_back(str1);
        }
        istringstream sss(sentence2);
        string str2;
        while (sss >> str2){
            v2.push_back(str2);
        }
        int l1 = 0, l2 = 0, r1 = v1.size()-1, r2 = v2.size()-1;
        while (l1 <= r1 && l2 <= r2){
            if (v1[l1] == v2[l2]){
                l1++;
                l2++;
            }
            else if (v1[r1] == v2[r2]){
                r1--;
                r2--;
            }
            else return false;
        }
        return true;
    }
};