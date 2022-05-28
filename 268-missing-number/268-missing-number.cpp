class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = -1;
        for (int i=0; i<nums.size(); i++){
            if (i == nums[i]){
                continue;
            }
            else{
                ans = i;
                break;
            }
        }
        if (ans == -1) ans = nums[nums.size() - 1] + 1;
        return ans;
    }
};