class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int i;
        int n = ratings.size();
        int result = 0;
        vector<int> count(n);
        for (i = 0; i < n; i++)
        {
            count[i] = 1;
        }
        for (i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                count[i] = count[i - 1] + 1;
            }
        }
        for (i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && count[i] <= count[i + 1])
            {
                count[i] = count[i + 1] + 1;
            }
        }
        for (i = 0; i < n; i++)
        {
            result += count[i];
        }
        return result;
    }
};