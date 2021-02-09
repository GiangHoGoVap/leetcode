class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int result = 0;
        for (int i=0; i<n; i++){
            if (nums[i] == 1){
                count = count + 1;
                if (result < count) result = count;
            }
            if (nums[i] == 0){
                count = 0;
            }
        }
        
        return result;
    }
};