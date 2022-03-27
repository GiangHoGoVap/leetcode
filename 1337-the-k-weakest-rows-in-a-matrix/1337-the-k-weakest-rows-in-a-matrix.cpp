class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> temp;
        vector<int> ans;
        for (int i=0; i<mat.size(); i++){
            int soldier = 0;
            for (int j=0; j<mat[i].size(); j++){
                if (mat[i][j] == 1) soldier++;
            }
            temp.push_back({soldier, i});
        }
        sort(temp.begin(), temp.end());
        for (int i=0; i<k; i++){
            ans.push_back(temp[i].second);
        }
        return ans;
    }
};