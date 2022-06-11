class Solution
{
public:
	int minOperations(vector<int> &nums, int x)
	{
		int target = accumulate(nums.begin(), nums.end(), 0);
		target -= x;
		if (target == 0)
			return nums.size();
		if (target < 0)
			return -1;
		int s = 0, e = 0, sum = 0, ans = INT_MAX;
		while (e < nums.size() && s <= e)
		{
			if (sum <= target)
			{
				sum += nums[e++];
			}
			while (sum >= target)
			{
				if (sum == target)
					ans = fmin(ans, nums.size() - e + s);
				sum -= nums[s++];
			}
		}
		return ans == INT_MAX ? -1 : ans;
	}
};