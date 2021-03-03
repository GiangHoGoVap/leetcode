class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans;
        bool flag = false;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){
            if (i != nums[i]){
                ans = i;
                flag = true;
                break;
            }
        }
        if (!flag) return nums[nums.size()-1] + 1;
        return ans;
    }
};