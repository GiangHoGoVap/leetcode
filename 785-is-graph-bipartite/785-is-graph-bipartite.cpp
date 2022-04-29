class Solution
{
public:
	bool checkBipartite(int curr, vector<int> &visited, vector<vector<int>> &graph)
	{
		int size = graph.size();
		vector<int> color(size, -1);
		vector<int> parent(size, -1);
		visited[curr] = 1;
		color[curr] = 0;
		queue<int> nodes;
		nodes.push(curr);
		while (!nodes.empty())
		{
			int currNode = nodes.front();
			nodes.pop();
			for (auto nbr : graph[currNode])
			{
				if (!visited[nbr])
				{
					color[nbr] = (color[currNode] == 0) ? 1 : 0;
					parent[nbr] = currNode;
					visited[nbr] = 1;
					nodes.push(nbr);
				}
				else
				{
					if (nbr != parent[currNode] && color[nbr] == color[currNode])
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	bool isBipartite(vector<vector<int>> &graph)
	{
		vector<int> visited(graph.size(), 0);
		for (int i = 0; i < graph.size(); i++)
		{
			if (!visited[i])
			{
				if (!checkBipartite(i, visited, graph))
				{
					return false;
				}
			}
		}
		return true;
	}
};