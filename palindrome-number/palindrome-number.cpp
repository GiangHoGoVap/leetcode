class Solution {
public:
    bool isPalindrome(int x) {
        int divisor = 1;
        while (x / divisor >= 10){
            divisor *= 10;
        }
        while (x != 0){
            int firstDigit = x / divisor;
            int lastDigit = x % 10;
            if (firstDigit != lastDigit || x < 0) return false;
            x = (x % divisor) / 10;
            divisor /= 100;
        }
        return true;
    }
};