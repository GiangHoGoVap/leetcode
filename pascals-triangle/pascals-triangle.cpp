class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1) return ans;
        ans.push_back({1,1});
        if (numRows == 2) return ans;
        for(int i=3; i<=numRows; i++){
            vector<int> temp, prev = ans[i-2];
            temp.push_back(1);
            for(int j=1; j<prev.size(); j++){
                temp.push_back(prev[j] + prev[j-1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};