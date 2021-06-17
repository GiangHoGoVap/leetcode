class Solution
{
public:
	int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
	{
		int n = nums.size();
		int count = 0, start = -1, prev = 0;
		for (int i = 0; i < n; i++)
		{

			if (nums[i] < left)
				count += prev;
			else if (nums[i] >= left && nums[i] <= right)
			{
				prev = i - start;
				count += prev;
			}
			else
				start = i, prev = 0;
		}
		return count;
	}
};