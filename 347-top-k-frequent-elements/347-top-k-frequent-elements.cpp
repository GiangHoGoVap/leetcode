class Solution
{
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		unordered_map<int, int> mp;
		for (int i = 0; i < nums.size(); i++)
			mp[nums[i]]++;
		vector<vector<int>> count(nums.size() + 1);
		vector<int> res;
		for (auto &i : mp)
			count[i.second].push_back(i.first);
		for (int i = nums.size(); i >= 0; i--)
		{
			for (int j = 0; j < count[i].size() && k > 0; j++, k--)
				res.push_back(count[i][j]);
			if (k <= 0)
				break;
		}
		return res;
	}
};