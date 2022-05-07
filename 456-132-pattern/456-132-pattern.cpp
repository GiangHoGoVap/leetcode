class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int second =  -2147483648;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < second)
                return true;
            while (s.size() > 0 && nums[i] > s.top()){
                second = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};