class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int type = 1;
        std::sort(candyType.begin(), candyType.end());
        for (int i=0; i<candyType.size(); i++){
            if (i == candyType.size() - 1) break;
            if (candyType[i] != candyType[i+1]) type++;
        }
        int maxi = candyType.size() / 2;
        if (type > maxi) return maxi;
        return type;
    }
};