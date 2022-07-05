class Solution
{
public:
	int longestConsecutive(vector<int> &nums)
	{
		unordered_set<int> s;
		if (nums.size() == 0)
		{
			return 0;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			s.insert(nums[i]);
		}
		int count = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!s.count(nums[i] - 1))
			{
				int curr_num = nums[i];
				int curr_count = 0;
				while (s.find(curr_num) != s.end())
				{
					curr_count++;
					curr_num++;
				}
				count = max(count, curr_count);
			}
		}
		return count;
	}
};