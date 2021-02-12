class Solution {
public:
    double trimMean(vector<int>& arr) {
        int x = arr.size()/20, sum = 0;
        sort(arr.begin(),arr.end());
        for(int i=x; i<arr.size()-x; i++){
            sum += arr[i];
        }
        return (double)sum/(arr.size()-2*x);
    }
};