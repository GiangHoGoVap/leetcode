class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s1;
        int j=0;
        for(int i=0;i<pushed.size();i++)
        {
            s1.push(pushed[i]);
            cout<<s1.top();
            while(!s1.empty()&&s1.top()==popped[j])
            {
                s1.pop();
                j++;
            }
        }
        return s1.empty();
    }
};