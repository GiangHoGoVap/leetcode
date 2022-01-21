class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currentTank = 0;
        int result = 0;
        for(int i = 0; i < gas.size(); i++) {
            totalTank += gas[i] - cost[i]; 
            currentTank += gas[i] - cost[i];
            if(currentTank < 0) {
                currentTank = 0;
                result = i+1;
            }
        }
        if(totalTank < 0) return -1;
        return result;
    }
};