class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = 1; 
        while(j < nums.size()){
            if(nums[i] != nums[j]){
                return nums[i];
            }else{
                i += 2;
                j += 2;
            }
        }
        return nums[i];
    }
};