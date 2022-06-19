class Solution
{
public:
	vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
	{
		sort(products.begin(), products.end());
		int n = products.size();
		int flag[n];
		memset(flag, 0, sizeof(flag));
		vector<vector<string>> ans(searchWord.size());
		for (int i = 0; i < searchWord.size(); i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (flag[j] == 0)
				{
					if (i < products[j].size() && products[j][i] == searchWord[i])
					{
						if (ans[i].size() < 3)
							ans[i].push_back(products[j]);
					}
					else
						flag[j] = 1;
				}
			}
		}
		return ans;
	}
};