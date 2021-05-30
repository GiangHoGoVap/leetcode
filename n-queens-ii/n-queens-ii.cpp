class Solution
{
public:
	int find(int n, int left, int i, int r, vector<int> &rows, vector<int> &d1, vector<int> &d2)
	{
		if (left == 0)
			return 1;
		int j, sum = 0;
		for (j = r; j < n; j++)
		{
			if (rows[j] || d1[i + j] || d2[n - 1 + i - j])
				continue;
			rows[j] = d1[i + j] = d2[n - 1 + i - j] = 1;
			sum += find(n, left - 1, i + 1, 0, rows, d1, d2);
			rows[j] = d1[i + j] = d2[n - 1 + i - j] = 0;
		}
		return sum;
	}
	int totalNQueens(int n)
	{
		vector<int> rows(n), d1(2 * n - 1), d2(2 * n - 1);
		return find(n, n, 0, 0, rows, d1, d2);
	}
};