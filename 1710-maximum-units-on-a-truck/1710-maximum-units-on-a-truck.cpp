class Solution
{
public:
	int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
	{
		sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &first, vector<int> &second)
			 { return first[1] > second[1]; });
		int ans = 0;
		for (auto box : boxTypes)
		{
			int x = min(box[0], truckSize);
			ans += (x * box[1]);
			truckSize -= x;
			if (!truckSize)
				break;
		}
		return ans;
	}
};