class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int ans = 0;
        for (auto i : ops){
            if (i == "C") s.pop();
            else if (i == "D"){
                int temp = s.top();
                temp = temp*2;
                s.push(temp);
            }
            else if (i == "+"){
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.push(temp1);
                int res = temp1 + temp2;
                s.push(res);
            }
            else{
                int temp = stoi(i);
                s.push(temp);
            }
        }
        while (!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};