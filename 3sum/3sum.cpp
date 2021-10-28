class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            long sum = -1 * nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while(start < end) {
                if((long)nums[start] + (long)nums[end] == sum) {
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[start]);
                    vec.push_back(nums[end]);
                    ans.push_back(vec);
                    if(nums[start] == nums[end]) break;
                    while(start < end && (long)nums[start] + (long)nums[end] == sum) {
                        ++start;
                    }
                    while(start < end && (long)nums[start] + (long)nums[end] == sum) {
                        --end;
                    }
                }
                else if((long)nums[start] + (long)nums[end] < sum) {
                    ++start;
                }
                else {
                    --end;
                }
            }
        }
        return ans;
    }
};