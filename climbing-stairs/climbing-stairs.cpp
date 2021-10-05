class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
	    if (n <= 1){
		    return n;
	    }
	    for(int i=2; i<=n; i++){
		    int t = a + b;
		    a = b;
		    b = t;
	    }
	    return b;
    }
};