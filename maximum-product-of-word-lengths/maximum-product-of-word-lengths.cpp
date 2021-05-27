class Solution
{
public:
	int maxProduct(vector<string> &words)
	{
		int ans = 0;
		int n = words.size();
		vector<vector<bool>> mark(n, vector<bool>(26, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < words[i].length(); j++)
				mark[i][words[i][j] - 'a'] = true;
		}
		for (int i = 0; i < n; i++)
		{
			int n1 = words[i].length();
			for (int j = i + 1; j < n; j++)
			{
				int n2 = words[j].length();
				for (int k = 0; k < 26; k++)
				{
					if (mark[i][k] and mark[j][k])
						goto h;
				}
				ans = max(ans, n1 * n2);
			h:;
			}
		}
		return ans;
	}
};