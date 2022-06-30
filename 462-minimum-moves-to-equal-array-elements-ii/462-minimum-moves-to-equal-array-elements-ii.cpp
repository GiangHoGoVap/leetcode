class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = n/2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += abs(nums[i] - nums[mid]);
        }
        return count;
    }
};