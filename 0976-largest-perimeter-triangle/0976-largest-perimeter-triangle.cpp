class Solution {
public:
    bool canBeTriangle(int a, int b, int c) { 
        return (((a + b) > c) && ((b + c) > a) && ((a + c) > b)); 
    }
    
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end(), greater<int>());
		for (int i = 0; i + 2 < A.size(); i++) 
            if (canBeTriangle(A[i], A[i + 1], A[i + 2])) 
                return (A[i] + A[i + 1] + A[i + 2]);
		return 0;
	}
};