class Solution
{
public:
	int distance(vector<int> &pointA, vector<int> &pointB)
	{
		return abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]);
	}
	int minCostConnectPoints(vector<vector<int>> &points)
	{
		int ans = 0, n = points.size();
		vector<int> minCost(n, INT_MAX);
		minCost[0] = 0;
		vector<int> visited(n);
		int current_point = 0;
		while (current_point >= 0)
		{
			visited[current_point] = true;
			int minCurrent = INT_MAX;
			int next_point = -1;
			for (int point = 0; point < n; point++)
			{
				if (visited[point] || point == current_point)
					continue;
				minCost[point] = min(distance(points[current_point], points[point]), minCost[point]);
				if (minCost[point] < minCurrent)
				{
					minCurrent = minCost[point];
					next_point = point;
				}
			}
			ans += (minCurrent == INT_MAX) ? 0 : minCurrent;
			current_point = next_point;
		}
		return ans;
	}
};