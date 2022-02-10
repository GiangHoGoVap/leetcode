class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int N = nums.size();
        unordered_map<int, int> m;
        int currentSum = 0;
        for(int i=0; i<N; ++i){
            currentSum += nums[i];
            if(currentSum == k)
                ans++;
            if(m.find(currentSum - k) != m.end())
                ans += m[currentSum - k];
            m[currentSum] += 1;
        }
        return ans;
    }
};