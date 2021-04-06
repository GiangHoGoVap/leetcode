class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char ch = coordinates[0];
        int num = coordinates[1] - '0';
        if (ch == 'a' || ch == 'c' || ch == 'e' || ch == 'g'){
            if (num % 2 == 0) return true;
            else return false;
        }
        else{
            if (num % 2 == 0) return false;
            else return true;
        }
    }
};