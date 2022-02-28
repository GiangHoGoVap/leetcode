class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ret;
        int num, i = 0;

        while (i < nums.size())
        {
            string ans = "";
            num = nums[i++];
            int p = num;
            ans = to_string(num);
            while (i < nums.size() && num + 1 == nums[i])
                num = nums[i++];
            if (p != num)
                ans += "->" + to_string(num);
            ret.push_back(ans);
        }
        return ret;
    }
};