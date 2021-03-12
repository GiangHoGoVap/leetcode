class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int local_max = 0;
        int global_max = INT_MIN;
        for (int i=0; i<n; i++){
            local_max = max(nums[i], nums[i] + local_max);
            if (local_max > global_max){
                global_max = local_max;
            }
        }
        return global_max;
    }
};