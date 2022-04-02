class Solution {
public:
    bool check(string s , int i) {
        int p1 = 0, p2 = s.length() - 1;
        while (p1 < p2) {
            if (p1 == i) { p1++; continue; }
            if (p2 == i) { p2--; continue; }
        
            if (s[p1] != s[p2]) {
                return false;
            }
            
            p1++;
            p2--;
        }
        
        return true;
    } 
    
    bool validPalindrome(string s) {
        int p1 = 0 , p2 = s.length() - 1;
        while (p1 < p2) {
            if (s[p1] == s[p2]) {
                p1++;
                p2--;
                continue;
            }
            
            if (check(s, p1)) {
                return true;
            }
            
            if (check(s, p2)) {
                return true;
            }
            
            return false;
        }
        
        return true;
    }
};