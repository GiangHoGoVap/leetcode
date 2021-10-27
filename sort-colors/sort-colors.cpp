class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int begin = 0;
        int end = nums.size() - 1;
        int i = 0;
        if (nums.size() <= 1)
        {
            return;
        }
        while (i < nums.size() && begin < end)
        {
            if (nums[i] == 0)
            {
                int temp = nums[begin];
                nums[begin] = nums[i];
                nums[i] = temp;
                begin++;
                i++;
            }
            else if (nums[i] == 2 && end > i)
            {
                int temp = nums[end];
                nums[end] = nums[i];
                nums[i] = temp;
                end--;
            }
            else
            {
                i++;
            }
        }
    }
};