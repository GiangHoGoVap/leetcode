class Solution {
    vector<int> v;
    vector<vector<int>> ans;
    void backtracking(vector<int>nums, vector<int> v, int idx){
        if (idx == nums.size()) ans.push_back(v);
        else{
            v.push_back(nums[idx]);
            backtracking(nums, v, idx + 1);
            v.pop_back();
            backtracking(nums, v, idx + 1);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, v, 0);
        return ans;
    }
};