class Solution {
public:
    int isMatching(string &target,string stamp){
        for(int i=0; i<target.length(); i++){
            int j = 0;
            int matches = 0;
            for(j=0; j<stamp.length(); j++){
                if(target[i+j] == stamp[j]) matches++;
                else if(target[i+j] == '?') continue;
                else break;
            }
            if(j == stamp.length() && matches != 0){
                for(j = 0; j<stamp.length(); j++){
                    target[i + j] = '?';
                }
                 return i;
            }
        }
        return -1;
    }
    vector<int> movesToStamp(string stamp, string target) {
        string seq(target.length(),'?');
        vector<int> res;
        while(target != seq){
            int matching_id = isMatching(target,stamp);
            if(matching_id == -1){
                return {};
            }
            res.push_back(matching_id);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};