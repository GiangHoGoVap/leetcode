class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res(nums1.size(), -1);
        for (auto i = 0; i < nums1.size(); i++)
        {
            checkNum(res, nums2, nums1[i], i);
        }
        return res;
    }

private:
    void checkNum(vector<int> &res, vector<int> &nums2, int value, int pos)
    {
        int index = find(nums2.begin(), nums2.end(), value) - nums2.begin() + 1;
        for (int i = index; i < nums2.size(); i++)
        {
            if (nums2[i] > value)
            {
                res[pos] = nums2[i];
                break;
            }
        }
    }
};