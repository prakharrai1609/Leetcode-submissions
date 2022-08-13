class Solution {
public:
    string decodeString(string s, int &idx) {
        string res = "";
        int N = s.length();
        
        while (idx < N and s[idx] != ']') {
            if (!isdigit(s[idx])) {
                res += s[idx++];
            } else {
                int rep = 0;
                while (isdigit(s[idx])) 
                    rep = rep * 10 + (s[idx++] - '0');
                idx++;
                string temp = decodeString(s, idx);
                idx++;
                
                while (rep--)
                    res += temp;
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};