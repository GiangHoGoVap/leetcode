class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maximum = -1;
        int index = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] > maximum){
                maximum = nums[i];
                index = i;
            }
        }
        for (int i=0; i<nums.size(); i++){
            if (maximum == nums[i]) continue;
            if (maximum < 2*nums[i]){
                return -1;
            }
        }
        return index;
    }
};