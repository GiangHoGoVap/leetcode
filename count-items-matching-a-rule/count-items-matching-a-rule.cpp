class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        for (int i=0; i<items.size(); i++){
            if (ruleKey == "type"){
                if (ruleValue == items[i][0]) cnt++;
            }
            else if (ruleKey == "color"){
                if (ruleValue == items[i][1]) cnt++;
            }
            else{
                if (ruleValue == items[i][2]) cnt++;
            }
            
        }
        return cnt;
    }
};