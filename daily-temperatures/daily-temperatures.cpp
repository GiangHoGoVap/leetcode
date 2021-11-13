class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> temp;
        temp.push(n - 1);
        for (int i = n - 2; i >= 0; --i)
        {
            while (!temp.empty() and temperatures[temp.top()] <= temperatures[i])
            {
                temp.pop();
            }
            if (!temp.empty())
            {
                res[i] = temp.top() - i;
            }
            temp.push(i);
        }
        return res;
    }
};