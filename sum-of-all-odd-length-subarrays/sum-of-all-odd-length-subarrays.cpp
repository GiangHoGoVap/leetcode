class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int i=0; i<arr.size(); i++){
            ans += arr[i];
        }
        int count = 3;
        while (count <= arr.size()){
            if (count % 2 != 0){
                for (int i=0; i<=(arr.size()-count); i++){
                    for (int j=i; j<i+count; j++){
                        ans += arr[j];
                    }
                }
            }
            count++;
        }
        return ans;
    }
};