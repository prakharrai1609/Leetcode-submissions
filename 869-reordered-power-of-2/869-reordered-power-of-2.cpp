class Solution {
    bool ans = false;
public:
    bool ispower(int num) {
        return (num and !((num) & (num - 1)));
    }
    
    void permute(string s, int idx) {
        if (idx == s.length()) {
            if (ispower(stoi(s)) and s[0] != '0') {
                ans = true;
                return;
            }
        }
            
        for (int i = idx; i < s.length(); i++) {
            swap(s[i], s[idx]);
            permute(s, idx + 1);
        }
    }
    
    bool reorderedPowerOf2(int n) {
        permute(to_string(n), 0);
        return ans;
    }
};