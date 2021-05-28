class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int i = 0, j = 0, n = nums.size();
        int ans = 0, cnt = 0;
        while(i < n) {
            while(j < n && mp.find(nums[i]) != mp.end()) {
                mp.erase(nums[j]);
                cnt -= nums[j];j++;
            }
            mp[nums[i]] = 1;
            cnt += nums[i];
            ans = max(ans,cnt);
            i++;
        }
        return ans;
    }
};