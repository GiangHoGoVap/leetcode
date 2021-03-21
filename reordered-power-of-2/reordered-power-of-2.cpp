class Solution {
public:
    string sorted_num(int n){
        string res = to_string(n);
        sort(res.begin(), res.end());
        return res;
    }
    bool reorderedPowerOf2(int N) {
        string str = sorted_num(N);
        for (int i=0; i<32; i++){
            if (str == sorted_num(1 << i)) return true;
        }
        return false;
    }
};