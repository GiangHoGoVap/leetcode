class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int dict[26]{};
        for (auto& b: B){
            int count[26]{};
            for (auto c: b){
                count[c - 'a']++;
            }
            for (int i = 0; i < 26; i++){
                dict[i] = max(dict[i], count[i]);
            }
        }
        vector<string> res;
        for (auto& a: A){
            int count[26]{};
            for (auto c: a){
                count[c - 'a']++;
            }
            bool isSubset = true;
            for (int i = 0; i < 26; i++){
                if (count[i] < dict[i]){
                    isSubset = false;
                    break;
                }
            }
            if (isSubset)
                res.push_back(a);
        }
        return res;
    }
};