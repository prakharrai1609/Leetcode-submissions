class Solution {
public:
    bool isValid(string s) {
        map<char, char> open;
        open['('] = ')', open['{'] = '}', open['['] = ']';
        
    
        stack<char> st;
        
        for (char c : s) {
            if (open.find(c) != open.end()) {
                st.push(c);
            } else {
                if (st.empty()) return false;
                
                if (open[st.top()] == c) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};