class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int count = 0;
        int ans;
        sort(nums.begin(), nums.end());
        for(int i = nums.size() - 1; i >= 0; i--) {
            count++;
            if(count == k) {
                ans = nums[i];
            }
        }
        return ans;
    }
};