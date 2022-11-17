class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (D - B) * (C - A) - max((long)min(C, G) - max(A, E), 0L) * max((long)min(D, H) - max(B, F), 0L) + (H - F) * (G - E) ;
    }
};