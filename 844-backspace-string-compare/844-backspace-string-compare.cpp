class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        for (char c : s) {
            if (c == '#' and !s1.empty()) s1.pop();
            else if (c != '#') s1.push(c);
        }
        
        for (char c : t) {
            if (c == '#' and !s2.empty()) s2.pop();
            else if (c != '#') s2.push(c);
        }
        
        while (!s1.empty() and !s2.empty()) {
            if (s1.top() != s2.top()) return false;
            s1.pop();
            s2.pop();
        }
        
        if (!s1.empty() or !s2.empty()) return false;
        return true;
    }
};