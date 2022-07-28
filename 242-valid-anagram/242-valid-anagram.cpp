class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(begin(s), end(s));
        sort(begin(t), end(t));
        int i = 0, N = s.length();
        
        while (i < N) {
            if (s[i] != t[i])
                return false;
            i++;
        }
        
        return true;
    }
};