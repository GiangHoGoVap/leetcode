class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<string> v;
        string temp;
        for (int i = 0; i < number.size(); i++) {
            temp = number;
            if (temp[i] == digit) {
                temp.erase(i, 1);
                v.push_back(temp);
            }
        }
        sort(v.begin(), v.end());
        return v[v.size() - 1];    
    }
};