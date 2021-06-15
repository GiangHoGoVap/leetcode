class Solution
{
private:
	int target_side, n;
	bool dfs(vector<int> &nums, int idx, vector<int> &sides)
	{
		if (idx == n)
			return true;
		for (int i = 0; i < 4; ++i)
		{
			if (sides[i] + nums[idx] > target_side)
				continue;
			int j = i - 1;
			while (j >= 0 && sides[i] != sides[j])
				--j;
			if (j != -1)
				continue;
			sides[i] += nums[idx];
			if (dfs(nums, idx + 1, sides))
				return true;
			sides[i] -= nums[idx];
		}
		return false;
	}

public:
	bool makesquare(vector<int> &nums)
	{
		n = nums.size();
		if (n < 4)
			return false;
		target_side = accumulate(nums.begin(), nums.end(), 0);
		if (target_side & 3)
			return false;
		target_side >>= 2;
		vector<int> sides(4);
		sort(nums.rbegin(), nums.rend());
		return dfs(nums, 0, sides);
	}
};