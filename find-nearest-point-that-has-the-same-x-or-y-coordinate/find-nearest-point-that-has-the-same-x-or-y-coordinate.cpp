class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int smallest_dis = 100000;
        int ans = -1;
        int dis;
        for (int i=0; i<points.size(); i++){
            if (x == points[i][0] || y == points[i][1]){
                dis = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (dis < smallest_dis){
                    smallest_dis = dis;
                    ans = i;
                }
            }
        }
        return ans;
    }
};