class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> f;
        
        if (s.length() == 0) return 0;
        f[s[0]]++;
        
        int i = 1, j = 0, len = 1;
        
        while (i < s.length()) {
            while (f[s[i]] and i != j) {
                f[s[j]]--;
                j++;
            }
            f[s[i]]++;
            len = max(len, i - j + 1);
            i++;
        }
        
        return len;
    }
};