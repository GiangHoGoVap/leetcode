class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> freq(100001, 0);
        int maxNum = INT_MIN;
        for (auto i : nums)
        {
            maxNum = max(maxNum, i);
            freq[i] += i;
        }
        int curPoints = freq[1], prevPoints = 0;
        for (int i = 2; i <= maxNum; i++)
        {
            int tmp = curPoints;
            curPoints = max(prevPoints + freq[i], curPoints);
            prevPoints = tmp;
        }
        return curPoints;
    }
};