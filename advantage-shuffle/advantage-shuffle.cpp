class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> ss(begin(A), end(A));
        for (auto i = 0; i < B.size(); ++i) {
            auto p = ss.upper_bound(B[i]);
            if (p != ss.end()) A[i] = *p;
            else{
                p = ss.begin(); 
                A[i] = *p;
            }
            ss.erase(p);
        }
        return A;
    }
};