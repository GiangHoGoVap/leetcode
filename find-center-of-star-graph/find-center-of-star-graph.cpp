class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        sort(edges[0].begin(), edges[0].end());
        int temp1 = edges[0][0];
        int temp2 = edges[0][1];
        int cnt1 = 0, cnt2 = 0;
        for (int i=1; i<edges.size(); i++){
            sort(edges[i].begin(), edges[i].end());
            if (temp1 == edges[i][0]) cnt1++;
            if (temp2 == edges[i][1]) cnt2++;
        }
        if (cnt1 > cnt2) return temp1;
        return temp2;
    }
};