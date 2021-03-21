class Solution {
public:
    int secondHighest(string s) {
        vector<int> v;
        for (int i=0; i<s.length(); i++){
            if (isdigit(s[i])){
                v.push_back(s[i] - '0');
            }
        }
        if (v.size() == 0) return -1;
        sort(v.begin(), v.end());
        int second = v[v.size()-1];
        bool flag = false;
        for (int i=v.size()-2; i>=0; i--){
            if (v[i] < second){
                second = v[i];
                flag = true;
                break;
            }
        }
        if (flag) return second;
        return -1;
    }
};