class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        int low = 0;
        int i = 0;
        while (i < len)
        {
            int tmp = nums[i];
            nums[low++] = nums[i++];
            if (i == len || nums[i] != tmp)
                continue;
            int j = i + 1;
            while (j < len && nums[j] == tmp)
                j++;
            nums[low++] = tmp;
            i = j;
        }
        return low;
    }
};