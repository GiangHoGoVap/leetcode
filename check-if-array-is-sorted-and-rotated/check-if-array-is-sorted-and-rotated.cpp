class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] > nums[(i+1)%size]) count++;
        }
        if (count <= 1) return true;
        return false;
    }
};