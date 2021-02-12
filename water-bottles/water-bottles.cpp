class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, temp = numBottles;
        while (temp >= numExchange){
            ans += (temp / numExchange);
            temp = (temp / numExchange) + (temp % numExchange);
        }
        return ans;
    }
};