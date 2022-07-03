class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int diff = nums[1] - nums[0], curr_diff;
        int count = diff != 0 ? 2 : 1;
        for (int i = 1; i < nums.size()-1; i++){
            curr_diff = nums[i+1] - nums[i];
            if (diff <= 0 && curr_diff > 0 || diff >= 0 && curr_diff < 0){
                count++;
                diff = curr_diff;
            }
        }
        return count;
    }
};