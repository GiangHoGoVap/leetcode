class Solution {
public:
    double average(vector<int>& salary) {
        int total = 0;
        int cnt = 0;
        sort(salary.begin(), salary.end());
        for (int i = 1; i < salary.size() - 1; i++){
            total += salary[i];
            cnt++;
        }
        return double(total) / cnt;
    }
};