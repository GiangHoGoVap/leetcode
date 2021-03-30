class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(begin(envelopes),end(envelopes),[]
             (const vector<int> &a,const vector<int> &b){
                 return (a[0]==b[0] ? a[1]<b[1] : a[0]<b[0]);
             });
        vector<int> dp(envelopes.size(),1);
        for(int i=1; i<envelopes.size(); i++){
            for(int j=0; j<i; j++){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]){
                    if(dp[i] < dp[j]+1)
                        dp[i] = dp[j]+1;
                }
            }
        }
        return *max_element(begin(dp),end(dp));
    }
};