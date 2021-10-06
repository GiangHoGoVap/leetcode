class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (auto num : nums) {
            int index = abs(num) - 1;
            if (nums[index] < 0)
                result.push_back(abs(num));
            else
                nums[index] *= -1;
        }
        return result;
    }
};