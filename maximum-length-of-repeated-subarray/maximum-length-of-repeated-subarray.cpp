class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0, m = A.size(), n = B.size();
        for (int i = 0; i < m; i++) 
            ans = max(ans, helper(A, B, i, 0));
        for (int j = 1; j < n; j++) 
            ans = max(ans, helper(A, B, 0, j));
        return ans;
    }
private:
    int helper(vector<int>& A, vector<int>& B, int i, int j) {
        int len = 0, cnt = 0;
        for (;i < A.size() && j < B.size(); i++, j++) {
            if (A[i] == B[j]) 
                len = max(len, ++cnt);
            else 
                cnt = 0;
        }
        return len;
    }
};