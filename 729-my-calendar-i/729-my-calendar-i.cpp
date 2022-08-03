class MyCalendar {
    set<pair<int, int>> dates;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto date = dates.lower_bound({start, end});
        
        if ((date != dates.end() and !(date->first >= end)) or (date != dates.begin() and !(prev(date)->second <= start)))
            return false;
        
        dates.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */