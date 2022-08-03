class MyCalendar {
    vector<vector<int>> dates;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        int n = size(dates);
        
        if (n == 0) {
            dates.push_back({start, end});
            return true;
        }
        
        for (int i = 0; i < n; i++) {
            int ds = dates[i][0], de = dates[i][1];
            if (ds >= end or de <= start) 
                continue;
            else 
                return false;
        }
        
        dates.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */