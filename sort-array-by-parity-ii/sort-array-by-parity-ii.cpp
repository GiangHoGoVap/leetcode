class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        vector<int> v;
        vector<int> v1;
        vector<int> v2;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & 1)
            {
                v2.push_back(nums[i]);
            }
            else
            {
                v1.push_back(nums[i]);
            }
        }

        for (int i = 0; i < nums.size() / 2; i++)
        {
            v.push_back(v1[i]);
            v.push_back(v2[i]);
        }
        return v;
    }
};