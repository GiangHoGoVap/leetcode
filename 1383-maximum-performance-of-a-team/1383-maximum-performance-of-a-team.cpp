class Solution
{
public:
	int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
	{

		vector<pair<int, int>> res;

		for (int i = 0; i < n; i++)
		{
			res.push_back({efficiency[i], speed[i]});
		}

		sort(begin(res), end(res), [](const pair<int, int> &p1, const pair<int, int> &p2)
			 {
				 if (p1.first == p2.first)
				 {
					 return p1.second > p2.second;
				 }
				 return p1.first > p2.first;
			 });

		priority_queue<int, vector<int>, greater<int>> pq;
		int i = 0;
		long ans = 0;
		long fans = 0;
		while (i < n)
		{

			if (pq.size() == k && res[i].second <= pq.top())
			{
				i++;
				continue;
			}
			pq.push(res[i].second);
			if (pq.size() > k)
			{

				int curr_speed = pq.top();
				pq.pop();
				ans -= curr_speed;
				ans = ans + (res[i].second);
				fans = max(fans, ans * (res[i].first));
			}
			else
			{

				ans = ans + (res[i].second);
				fans = max(fans, ans * (res[i].first));
			}
			i++;
		}

		return fans % 1000000007;
	}
};