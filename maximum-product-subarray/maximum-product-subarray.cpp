class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_pro = nums[0];
        int min_save = nums[0];
        int max_save = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(min_save, max_save);
            min_save = min(nums[i], min_save*nums[i]);
            max_save = max(nums[i], max_save*nums[i]);
            max_pro = max(max_pro, max_save);
        }
        return max_pro;
    }
};