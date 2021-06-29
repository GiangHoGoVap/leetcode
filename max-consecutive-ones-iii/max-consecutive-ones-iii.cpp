class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> q;
        int prev = -1;
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if (nums[i] == 0)
                q.push_back(i);
            if (q.size()>k)
            {
                prev = q.front();
                q.pop_front();
            }
            ans = max(ans,i-prev);
        }
        return ans;
    }
};