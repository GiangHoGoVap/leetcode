class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> ans;
        int temp = 0;
        for (auto x: nums) {
            if (umap.find(x) != umap.end()) {
                temp = x;
            }
            umap[x]++;
        }
        ans.push_back(temp);
        for (int i = 1; i <= nums.size(); i++) {
            if (umap.find(i) == umap.end()) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};