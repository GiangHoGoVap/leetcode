class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area;
		int maxArea = 0;
		int i = 0;
		stack<int> s;
		while(i < heights.size()){
			if(s.empty() or heights[s.top()] <= heights[i]){
				s.push(i);
				i++;
			}
			else{
				int temp = s.top();
				s.pop();
				if(s.empty()){
					area = heights[temp] * i;
				}
				else{
					area = heights[temp] * (i - s.top() - 1);
				}
				if(area > maxArea){
					maxArea = area;
				}
			}
		}
		while(!s.empty()){
			int temp = s.top();
			s.pop();
			if(s.empty()){
				area = heights[temp] * i;
			}
			else{
				area = heights[temp] * (i - s.top() - 1);
			}
			if(area > maxArea){
				maxArea = area;
			}
		}
		return maxArea;
    }
};