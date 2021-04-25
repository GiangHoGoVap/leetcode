class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size(); //row end
		if (n == 0) return;
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for(int i=0; i<n; i++){
			int l = 0, r = n-1;
			while(l < r){
				swap(matrix[i][l++], matrix[i][r--]);
			}
		}
	}
};