class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if (arr.size() <= 1) return arr[0];
        int n = arr.size();
        int cnt[111111];
        double threshold = 0.25 * n;
        for (int i=0; i<n; i++){
            cnt[arr[i]]++;
        }
        int ans;
        for (int i=0; i<n; i++){
            if (cnt[arr[i]] > threshold) ans = arr[i];
        }
        return ans;
    }
};