class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        int f1[26] = {0}, f2[26] = {0}, N = s.length();
    
        for (int i = 0; i < N; i++) {
            f1[s[i] - 'a']++;
            f2[t[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++)
            if (f1[i] != f2[i])
                return false;
        
        return true;
    }
};


/*  TIME C : NLOGN
    SPACE : 1
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

**/