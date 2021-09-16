class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int m = arr.size(), res = 0, cnt = 0;
        vector<int> ans;
        for (int i = 1; i < m; i++)
        {
            if (arr[i] == arr[i - 1])
                ans.push_back(-1);
            else if (arr[i] > arr[i - 1])
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        for (int i = 0; i < m - 1; i++)
        {
            if (i == 0 && ans[i] != -1)
                cnt++;
            else if (ans[i] == -1)
                cnt = 0;
            else
            {
                if (ans[i] != ans[i - 1])
                    cnt++;
                else
                    cnt = 1;
            }
            res = max(res, cnt);
        }
        return res + 1;
    }
};