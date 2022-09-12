class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int size = tokens.size();
        if (size == 0) return 0;
        sort(tokens.begin(), tokens.end());
        int start = 0, end = size - 1, points = 0;
        while (start <= end) {
            while (start <= end && tokens[start] <= P) {
                P -= tokens[start];
                ++points;
                ++start;
            }
            if (start <= end && tokens[start] > P) {
                if (start < end && points > 0) {
                    P += tokens[end];
                    --points;
                }
                --end;
            }
        }
        return points;
    }
};