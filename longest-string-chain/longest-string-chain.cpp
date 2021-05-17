class Compare {
public:
    bool operator() (string& s1, string& s2) {
        return s1.size() < s2.size();
    }
};

Compare CompObject;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), CompObject);
        unordered_map<string,int> myMap;
        
        for (auto w : words)
            myMap[w] = 1;
    
        int res = 1;
        for (auto w : words)
            for (int i = 0; i < w.size(); ++i) {
                string temp = w.substr(0,i) + w.substr(i+1);
                if (myMap.count(temp) == 1) {
                    myMap[w] = myMap[temp] + 1;
                    res = max(res, myMap[w]);
                }
            }

        return res;
    }
};