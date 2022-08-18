class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            m[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto p : m) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};