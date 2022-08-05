class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        size_t combination_sum[1000] = {1, 0, 0};
        for (int i = 1; i <= target; i++){
            for (int j = 0; j < nums.size(); j++){
                combination_sum[i] += nums[j] <= i ? combination_sum[i - nums[j]] : 0;
            }
        } 
        return combination_sum[target];
    }
};