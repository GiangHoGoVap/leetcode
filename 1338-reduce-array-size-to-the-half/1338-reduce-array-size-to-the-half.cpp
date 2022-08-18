class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (auto i:arr){
            freq[i]++;
        }
        vector<int>freqVec;
        for (auto i:freq){
            freqVec.push_back(i.second);
        }
        sort(freqVec.begin(),freqVec.end(),greater<int>());
        for(int i=1; i<freqVec.size(); i++){
            freqVec[i] += freqVec[i-1];
        }
        return 1 + (lower_bound(freqVec.begin(),freqVec.end(),arr.size()/2)-freqVec.begin());
    }
};