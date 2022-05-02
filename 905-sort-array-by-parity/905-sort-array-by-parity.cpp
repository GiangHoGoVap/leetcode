class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> evenNum, oddNum;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] % 2 == 0){
                evenNum.push_back(nums[i]);
            }
            else{
                oddNum.push_back(nums[i]);
            }
        }
        evenNum.insert(evenNum.end(), oddNum.begin(), oddNum.end());
        return evenNum;
    }
};