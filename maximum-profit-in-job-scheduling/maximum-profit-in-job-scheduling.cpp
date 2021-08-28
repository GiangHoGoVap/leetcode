class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        set<int> _times;
        for (auto el : startTime) _times.insert(el);
        for (auto el : endTime) _times.insert(el);

        vector <vector <int> > jobs;
        vector <int> times(_times.begin(), _times.end());
        map <int, int> idx, _idx;

        for (int i = 0; i < times.size(); i++) 
            idx[times[i]] = i;
        
        for (int i = 0; i < n; i++) jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());

        int j = 1, m = times.size();
        vector <int> dp(m+5);
        for (int i = 0; i < n; i++) {
            int st = jobs[i][0], end = jobs[i][1], val = jobs[i][2];
            st = idx[st], end = idx[end];
            
            while(j <= st) {
                dp[j] = max(dp[j-1], dp[j]);
                j++;
            }
            dp[end] = max(dp[end], dp[st]+val);
        }
        while(j <= m)  {
            dp[j] = max(dp[j-1], dp[j]);
            j++;
        }
        return dp[m];
    }
};