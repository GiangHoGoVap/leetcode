class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        if (n < 3) return true;
        int VAL = A[0];
        for(int i=2; i<n; i++){
            if (A[i] < VAL) return false;
            VAL = max(VAL, A[i-1]);
        }
        return true;
    }
};