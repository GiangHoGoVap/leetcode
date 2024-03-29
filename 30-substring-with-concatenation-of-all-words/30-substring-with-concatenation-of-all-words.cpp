class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector <int> aResult;
        
        int aWordCount = words.size();
        if (aWordCount <= 0) { return aResult; }
        
        int aLen = words[0].size();
        if (aLen <= 0 || aLen > s.size()) { return aResult; }
        
        int aKeySize = aWordCount * aLen;
        if (aKeySize > s.size()) { return aResult; }
        
        unordered_map <string, int> aDic;
        for (auto aWord : words) { aDic[aWord]++; }
        
        int aCap = s.size() - aKeySize;
        
        // Start index of sliding window. Our stride will be aLen.
        for (int i=0;i<aLen;i++) {
            
            int aFront = i;
            int aRear = i;
            
            while (aFront <= aCap) {
                
                string aChunk = s.substr(aRear, aLen);
                
                if (aDic.find(aChunk) == aDic.end()) {
                    
                    // Close the front of the sliding window.
                    while (aFront < aRear) {
                        aDic[s.substr(aFront, aLen)]++;
                        aWordCount += 1;
                        aFront += aLen;
                    }
                    
                    // Advance past the current rear.
                    aRear += aLen;
                    aFront = aRear;
                    
                    continue;
                }
                
                if (aDic[aChunk] > 0) {
                    // We need to eliminate more of this word to match-all
                    aDic[aChunk]--;
                    aWordCount -= 1;
                    if (aWordCount == 0) {
                        aResult.push_back(aFront);
                    }
                    aRear += aLen;
                } else {
                    // We have too many of this word, advance the front of the window...
                    aDic[s.substr(aFront, aLen)]++;
                    aWordCount += 1;
                    aFront += aLen;
                }
            }
        }
        
        return aResult;
    }
};