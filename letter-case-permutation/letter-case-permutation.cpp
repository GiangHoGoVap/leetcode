class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        ans.push_back(S);
        for (int i=0; i<S.size(); i++){
            int m = ans.size();
            for (int j=0; j<m; j++){
                auto temp = ans[j];
                if (islower(temp[i])){
                    temp[i] = toupper(temp[i]);
                    ans.push_back(temp);
                }
                else if (isupper(temp[i])){
                    temp[i] = tolower(temp[i]);
                    ans.push_back(temp);
                }
                else continue;
            }
        }
        return ans;
    }
};