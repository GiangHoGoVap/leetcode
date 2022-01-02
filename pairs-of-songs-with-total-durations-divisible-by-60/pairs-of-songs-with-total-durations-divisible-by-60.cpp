class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int freq[60];
        memset(freq, 0, sizeof(freq));
        int ret = 0;
        for(auto& t: time){
            int mod = t % 60;
            ret += freq[(60 - mod) % 60];
            freq[mod]++;
        }
        return ret;
    }
};