class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int sum = 0, longestSub = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            sum += nums[i] == 0 ? -1 : 1;

            if (sum == 0)
            {
                if (i + 1 > longestSub)
                    longestSub = i + 1;
            }

            else if (mp.find(sum) != mp.end())
            {
                if (i - mp[sum] > longestSub)
                    longestSub = i - mp[sum];
            }

            else
                mp[sum] = i;
        }

        return longestSub;
    }
};