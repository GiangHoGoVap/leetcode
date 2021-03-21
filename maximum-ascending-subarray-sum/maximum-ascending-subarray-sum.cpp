class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            int sum = nums[i];
            for (int j=i+1; j<nums.size(); j++){
                if (nums[j] > nums[i]){
                    sum += nums[j];
                    i++;
                }
                else break;
            }
            if (sum > ans){
                ans = sum;
            }
        }
        return ans;
    }
};