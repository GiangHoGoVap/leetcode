class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int ans=0;
        for(int i=0; i<n and ans<pow(2,floor(log2(nums[i])+1))-1; i++){
            for(int j=i; j<n; j++){
                ans = max(ans, nums[i]^nums[j]);
            }
        }
        return ans;        
    }
};