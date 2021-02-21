class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        bool flag = false;
        for (long long i=1; i<=num/2; i++){
            if (i * i == num){
                flag = true;
                break;
            }
        }
        return flag;
    }
};