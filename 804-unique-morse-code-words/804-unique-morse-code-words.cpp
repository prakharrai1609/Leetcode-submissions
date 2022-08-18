class Solution {
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        
        for (string word : words) {
            string ans = "";
            for (char c : word) {
                ans += morse[c - 'a'];
            }
            s.insert(ans);
        }
        
        return s.size();
    }
};