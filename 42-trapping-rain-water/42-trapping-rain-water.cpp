class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int *stack = new int[n];
        int top = -1, j = 0;
        int water = 0;
        while (j < n && height[j] == 0) {
            j++;
        }
        for(int i = j; i < n; i++) {
            if (top < 0 || height[i] <= height[stack[top]]) {
                stack[++top] = i;
                continue;
            }
            while(top >= 0 && height[i] > height[stack[top]]) {
                int topn = height[stack[top--]];
                if (top < 0) break;
                int left = stack[top];
                int distance = i - left - 1;
                water += (distance*(min(height[left], height[i]) - topn));
            }
            stack[++top] = i;
        }
        return water; 
    }
};