class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        vector<int> ret;
        unordered_map<int, int> map1;
        for (int num : nums1)
            map1[num]++;
        for (int num : nums2)
        {
            if (map1.find(num) != map1.end() && map1[num] > 0)
            {
                ret.push_back(num);
                map1[num]--;
            }
        }
        return ret;
    }
};