class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        if (num < 10) return num;
        while (num > 0){
            int remainder = num % 10;
            sum += remainder;
            num /= 10;
        }
        return addDigits(sum);
    }
};