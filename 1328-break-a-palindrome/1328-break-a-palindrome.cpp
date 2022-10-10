class Solution {
public:
    string breakPalindrome(string s) {
        if (s.length() == 1) return "";
        int start = 0, end = s.length() - 1;
        set<string> v;
        while (start < s.length()) {
            if (start == end) {
                start++, end--;
                continue;
            }
            if (s[start] == s[end]) {
                if (s[start] == 'a') {
                    s[start] = 'b';
                    v.insert(s);
                    s[start] = 'a';
                } else {
                    char temp = s[start];
                    s[start] = 'a';
                    v.insert(s);
                    s[start] = temp;
                }
            } else {
                if (s[end] == 'a') {
                    char temp = s[start];
                    s[start] = 'b';
                    v.insert(s);
                    s[start] = temp;
                } else {
                    char temp = s[start];
                    s[start] = 'a';
                    v.insert(s);
                    s[start] = temp;
                }
            }
            start++, end--;
        }
        return *v.begin();
    }
};