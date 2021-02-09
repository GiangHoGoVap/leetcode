class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        else if (n == 2) return x * x;
        else if (n % 2 == 0) return myPow(myPow(x, n/2), 2);
        else if (n > 0) return x * myPow(myPow(x, n/2), 2);
        else return 1/x * myPow(myPow(x, n/2), 2);
        
    }
};