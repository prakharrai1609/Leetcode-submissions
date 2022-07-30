class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> f(26, 0);
        
        for (string word : words2) {
            vector<int> t(26, 0);
            for (char c : word) {
                t[c - 'a']++;
                f[c - 'a'] = max(f[c - 'a'], t[c - 'a']);
            }
        }
        
        vector<string> ans;
        for (string word : words1) {
            vector<int> t(26, 0);
            for (char c : word)
                t[c - 'a']++;
            
            int flag = 1;
            for (int i = 0; i < 26; i++) {
                if (f[i] > t[i]) {
                    flag = 0;
                    break;
                }
            }
            
            if (flag)
                ans.push_back(word);
        }
        
        return ans;
    }
};