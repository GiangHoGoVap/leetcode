int p[100000];
int N;

class Solution
{
public:
	int find(int x, int y)
	{
		if (p[x] == x and p[y] == y)
		{
			if (x < y)
			{
				p[y] = x;
				return x;
			}
			else
			{
				p[x] = y;
				return y;
			}
		}
		else
		{
			int newP = find(p[x], p[y]);
			p[x] = newP;
			p[y] = newP;
			return newP;
		}
	}

	int findParent(int x)
	{
		if (p[x] == x)
			return x;
		p[x] = findParent(p[x]);
		return p[x];
	}

	void unionFind(vector<vector<int>> &pairs)
	{
		for (int i = 0; i < pairs.size(); i++)
		{
			find(pairs[i][0], pairs[i][1]);
		}

		for (int i = 0; i < N; i++)
		{
			if (p[i] != i)
				findParent(i);
		}
	}

	string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
	{
		N = s.size();
		for (int i = 0; i < N; i++)
		{
			p[i] = i;
		}
		unionFind(pairs);
		unordered_map<int, priority_queue<int, vector<int>, greater<int>>> vq;
		for (int i = 0; i < N; i++)
		{
			vq[p[i]].push(s[i]);
		}
		string res = "";
		for (int i = 0; i < N; i++)
		{
			res += vq[p[i]].top();
			vq[p[i]].pop();
		}
		return res;
	}
};