class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        for(int i=1; i<S.size()-2; i++) {
            vector<string> left = makeNum(S.substr(1, i));
            vector<string> right = makeNum(S.substr(i+1, S.size()-2-i));
            for(int m=0; m<left.size(); m++) {
                for(int n=0; n<right.size(); n++) res.push_back("("+left[m]+", "+right[n]+")");
            }
        }
        return res;
    }
    vector<string> makeNum(string num) {
        vector<string> res;
        if(num[0] != '0' || num.size() == 1) res.push_back(num);
        for(int i=0; i<num.size()-1; i++) {
            if((num[0] == '0' && i != 0) || num.back() == '0') continue;
            res.push_back(num.substr(0, i+1) + "." + num.substr(i+1));
        }
        return res;
    }
};