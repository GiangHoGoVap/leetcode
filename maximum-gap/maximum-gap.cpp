class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        vector<pair<int, int>> min_max(n, {INT_MAX, INT_MIN});
        int mn = *min_element(nums.begin(), nums.end()), mx = *max_element(nums.begin(), nums.end());
        int diff = (mx - mn) / (n - 1);
        if ((mx - mn) % (n - 1)) diff++;
        if (diff == 0) return 0;
        for (int num : nums) {
            int ind = (num - mn) / diff;
            min_max[ind].first = min(min_max[ind].first, num);
            min_max[ind].second = max(min_max[ind].second, num);
        }
        int ans = 0;
        int curr_mn = INT_MIN, curr_mx = INT_MAX;
        int i = 0;
        while (i < n) {
            if (min_max[i].first == INT_MAX) {
                i++; continue;
            }
            if (curr_mx == INT_MAX) {
                curr_mx = min_max[i++].second; continue;
            }
            ans = max(ans, min_max[i].first - curr_mx);
            curr_mx = min_max[i++].second;
        }

        return ans;
    }
};