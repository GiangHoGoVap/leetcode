class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int count = 0;
        vector<int> res = {a, b, c};
        while (1){
            std::sort(res.begin(), res.end());
            if (!res[0]){
                count += min(res[1], res[2]);
                break;
            }
            else{
                count++;
                res[0]--;
                res[2]--;
            }
        }
        return count;
    }
};