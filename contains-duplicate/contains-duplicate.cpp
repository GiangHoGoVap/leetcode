class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){
            if (i == nums.size() - 1) break;
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};