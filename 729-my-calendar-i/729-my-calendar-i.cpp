class MyCalendar {
    vector<pair<int, int>> calendar;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto [s, e] : calendar)
            if (max(s, start) < min(e, end)) return false;
        
        calendar.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */