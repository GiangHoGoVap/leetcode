class Solution {
public:
    int numSquares(int n) {
        int i = sqrt(n);
        if (i * i == n) return 1;
        for (int i = 1; i * i < n; i++){
            int j = sqrt(n - i * i);
            if (j * j == (n - i * i)) return 2;
        }
        while (n % 4 == 0) 
            n /= 4;
        if (n % 8 == 7) return 4;
        return 3;
    }
};