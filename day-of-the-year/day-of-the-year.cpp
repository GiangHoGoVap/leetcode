class Solution {
public:
    bool isLeapYear(int year){
        if ((year % 4 == 0 && year % 100 != 0) || 
            (year % 100 == 0 && year % 400 == 0) ||
            (year % 400 == 0)) return true;
        return false;
    }
    int dayOfYear(string date) {
        int day = stoi(date.substr(8, 2));
        int month = stoi(date.substr(5, 2));
        int year = stoi(date.substr(0, 4));
        int ans = 0;
        ans += day;
        vector<int> daysEachMonth{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (month > 1){
            for (int i=0; i<month-1; i++){
                ans += daysEachMonth[i];
            }
        }
        if (isLeapYear(year) && month > 2){
            ans += 1;
        }
        return ans;
    }
};