class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        for (int tail = n - 1; tail > 1; tail--) {
        	int k = tail - 1, j = 0;
        	while (j < k) {
        		if (nums[j] + nums[k] > nums[tail]) {
        			res += (k - j);
        			k--;
        		} 
                else j++;
        	}
        }
        return res;
    }
};