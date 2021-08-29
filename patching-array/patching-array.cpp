class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long int s = nums.size();
        long long int i = 0, v = 0, p = 0;
        while (v < n && i < s)
        {
            if (v + 1 < nums[i])
            {
                p++;
                v += v + 1;
            }
            else
                v += nums[i++];
        }
        while (v < n)
        {
            v += v + 1;
            p++;
        }
        return p;
    }
};