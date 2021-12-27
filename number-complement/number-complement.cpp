class Solution {
public:
    int findComplement(int num) {
        return pow(2, ceil(log2(num+1L))) - 1 - num;
    }
};