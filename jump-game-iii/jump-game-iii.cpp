class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start >= 0 && start < arr.size() && arr[start] < arr.size()){
            int jump = arr[start];
            arr[start] += arr.size();
            return jump == 0 || canReach(arr, start + jump) || canReach(arr, start - jump);
        }
        return false;
    }
};