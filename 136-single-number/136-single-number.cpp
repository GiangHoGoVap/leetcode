class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());
        int ans = -1;
        bool flag = false;
        for (int i=0; i<nums.size()-1; i++){
            if (nums[i] == nums[i+1]){
                i++;
            }
            else{
                flag = true;
                ans = nums[i];
            }
        }
        if (flag) return ans;
        return nums[nums.size() - 1];
    }
};