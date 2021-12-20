class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        vector<vector<int>> ans;
        int j = 0, diff = INT_MAX;

        sort(begin(arr), end(arr));

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] < abs(diff))
                diff = abs(arr[i] - arr[i - 1]);
        }

        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i] - arr[i - 1]) == diff)
            {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};