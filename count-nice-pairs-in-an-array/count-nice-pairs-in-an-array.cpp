class Solution {
public:
    int rev(int x){
        int result = 0;
        int overflowCheck = 0;
        while (x){
            result = (long)result * 10 + x % 10;
            if (result / 10 != overflowCheck) {
                return 0;
            }
            overflowCheck = result;
            x /= 10;
        } 
        return result;
    }
    int countNicePairs(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int, long> umap;
        for (int i=0; i<nums.size(); i++){
            umap[(nums[i] - rev(nums[i]))]++;
        }
        for (auto x:umap){
            cnt += (x.second * (x.second - 1)/2) % 1000000007;
        }
        return cnt;
    }
};