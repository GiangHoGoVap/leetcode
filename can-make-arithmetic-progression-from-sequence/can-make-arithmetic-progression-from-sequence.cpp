class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dif = arr[1] - arr[0];
        for (int i=arr.size()-1; i>0; i--){
            if (arr[i] - arr[i-1] != dif) return false;
        }
        return true;
    }
};