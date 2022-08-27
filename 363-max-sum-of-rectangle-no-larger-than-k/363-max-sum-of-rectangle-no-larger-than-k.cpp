class Solution
{
public:
    int find(vector<int> &arr, int &k)
    {
        int sum = 0, ans = INT_MIN;
        set<int> s;
        for (auto i : arr)
        {
            sum += i;
            if (sum <= k)
            {
                ans = max(ans, sum);
            }

            auto it = s.lower_bound(sum - k);
            if (it != s.end())
            {
                ans = max(ans, sum - *it);
            }

            s.insert(sum);
        }
        return ans;
    }

    int maxSumSubmatrix(vector<vector<int>> &v, int k)
    {

        int ans = INT_MIN;
        for (int i = 0; i < v[0].size(); i++)
        {
            vector<int> arr(v.size(), 0);
            for (int j = i; j < v[0].size(); j++)
            {
                for (int k = 0; k < v.size(); k++)
                {
                    arr[k] += v[k][j];
                }

                ans = max(ans, find(arr, k));
            }
        }
        return ans;
    }
};