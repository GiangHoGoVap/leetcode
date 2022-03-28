class Solution
{
public:
	vector<vector<int>> largeGroupPositions(string s)
	{
		int i = 0, k = 0, count = 0;
		vector<vector<int>> ans;
		while (i < s.size() - 1)
		{
			if (s[i] == s[i + 1])
			{

				count++;
			}
			else
			{
				if (count >= 2)
				{
					ans.push_back(vector<int>{i - count, i});
				}
				count = 0;
			}
			i++;
		}

		if (count >= 2)
		{
			ans.push_back(vector<int>{i - count, i});
		}
		return ans;
	}
};