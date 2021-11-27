class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result( nums.size(), 1 );
        int prefixProd = 1;
        for( int i=1; i < nums.size(); i++ ) {
            prefixProd *= nums[i-1];
            result[i] = prefixProd * result[i];
        }
        int suffixProd = 1;
        for( int i=nums.size()-2; i >= 0; i-- ) {
            suffixProd *= nums[i+1];
            result[i] = result[i] * suffixProd;
        }
        return result;
    }
};