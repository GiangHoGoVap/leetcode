class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s;
        for (int i=0; i<words.size(); i++){
            s.insert(words[i]);
        }
        for (string x : words){
            for (int i=1; i<x.length(); i++){
                s.erase(x.substr(i));
            }
        }
        int len = 0;
        for (string word : s){
            len += word.length() + 1;
        }
        return len;
    }
};