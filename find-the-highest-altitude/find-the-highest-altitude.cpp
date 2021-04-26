class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitudes;
        altitudes.push_back(0);
        for (int i=0; i<gain.size(); i++){
            int next = gain[i] + altitudes[i];
            altitudes.push_back(next);
        }
        sort(altitudes.begin(), altitudes.end());
        return altitudes[altitudes.size()-1];
    }
};