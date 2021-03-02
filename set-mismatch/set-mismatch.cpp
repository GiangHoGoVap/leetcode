class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans, tempo;
        int temp, temp2;
        tempo.push_back(nums[nums.size()-1]);
        for (int i=nums.size()-1; i>0; i--){
            if (nums[i] != nums[i-1]) tempo.push_back(nums[i-1]);
        }
        sort(tempo.begin(), tempo.end());
        for (int i=0; i<tempo.size(); i++){
            if (i+1 != tempo[i]){
                temp2 = i+1;
                break;
            }
        }
        for (int i=nums.size()-1; i>0; i--){
            if (nums[i] == nums[i-1]){
                temp = nums[i];
                ans.push_back(nums[i]);
                break;
            }
        }
        ans.push_back(temp2);
        return ans;
    }
};