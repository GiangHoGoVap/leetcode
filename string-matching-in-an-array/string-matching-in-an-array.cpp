class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i=0; i<words.size(); i++){
            for (int j=0; j<words.size(); j++){
                auto found = words[j].find(words[i]);
                if (found != string::npos && words[i] != words[j]){
                    auto found2 = find(begin(ans), end(ans), words[i]);
                    if (found2 == end(ans)){
                        ans.push_back(words[i]);
                    }
                }
            }
        }
        return ans;
    }
};