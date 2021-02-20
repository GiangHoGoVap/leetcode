class Solution {
public:
    int romanToInt(string s) {
        int map[128];
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int ans = 0, len = s.length();
        int now = map[s[0]];
        for (int i=0; i<len-1; i++){
            int next = map[s[i+1]];
            if (now < next){
                ans -= now;
            }
            else{
                ans += now;
            }
            now = next;
        }
        return ans + now;
    }
};