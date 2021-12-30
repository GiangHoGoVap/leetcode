class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if ((K%2 == 0) or (K%5 == 0))
            return -1;
        
        int currentLength = 1;
        int currentModulus = currentLength % K;
        
        while (currentModulus != 0)
        {
            currentModulus *= 10;
            currentModulus += 1;
            currentModulus = currentModulus % K;
            currentLength += 1;                      
        }
        return currentLength;        
    }
};