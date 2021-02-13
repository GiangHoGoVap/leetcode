class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.size() == 0) return arr;
        vector<int> ans = arr;
        sort(arr.begin(), arr.end());
        int rank = 1;
        unordered_map<int, int> map;
        map[arr[0]] = rank;
        for (int i=1; i<arr.size(); i++){
            if (arr[i] != arr[i-1]) rank++;
            map[arr[i]] = rank;
        }
        for (int i=0; i<ans.size(); i++){
            ans[i] = map[ans[i]];
        }
        return ans;
    }
};