class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0, len = colors.length();
        int pSum = 0, pMax = 0;
        char curr = '\0';
        for (int i = 0; i <= len; ++i) {
            if (i == len) cost += pSum - pMax;
            else if (curr != colors[i]) {
                cost += pSum - pMax;
                pSum = pMax = neededTime[i];
                curr = colors[i];
            }
            else {
                pSum += neededTime[i];
                pMax = max(pMax, neededTime[i]);
            }
        }
        return cost;
    }
};
