class Solution {
private:
    const vector<string> numPad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    void helper(vector<string>& ans, string digits, int ind, string temp) {
        if (ind == digits.length()) {
            ans.push_back(temp);
            return;
        }
        
        int sNo = digits[ind] - '0';
        for (char c : numPad[sNo]) {
            helper(ans, digits, ind + 1, temp + c);
        }
    }
    
    vector<string> letterCombinations(string digits) {    
        vector<string> ans;
        
        if (digits.empty())
            return ans;
        
        helper(ans, digits, 0, "");
        return ans;
    }
};