class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int overflowCheck = 0;
        while (x){
            result = (long)result * 10 + x % 10;
            if (result / 10 != overflowCheck) {
                return 0;
            }
            overflowCheck = result;
            x /= 10;
        } 
        return result;
    }
};