class Solution {
public:
    void backtrack(vector<string>& vs, string ans, int open, int closed, int max) {
        if (ans.length() == 2 * max)
            vs.push_back(ans);
        if (open < max)
            backtrack(vs, ans + '(', open + 1, closed, max);
        if (closed < open)
            backtrack(vs, ans + ')', open, closed + 1, max);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        backtrack(vs, "", 0, 0, n);
        return vs;
    }
};

// Bit manipulation approach

// class Solution {
// public:
//     bool check(string brackets) {
//         stack<char> s;
//         for (char bracket : brackets) {
//             if (s.empty() and bracket == ')')
//                 return false;
            
//             if (s.empty() or s.top() == bracket)
//                 s.push(bracket);
//             else
//                 s.pop();
//         }
        
//         return s.empty();
//     }
    
//     vector<string> generateParenthesis(int n) {
//         int total = 2 * n;
//         vector<string> ans;
        
//         for (int i = 0; i < (1 << total); i++) {
//             string temp = "";
//             for (int j = 0; j < total; j++) {
//                 if (i & (1 << j)) {
//                     temp = ")" + temp;
//                 } else {
//                     temp = "(" + temp;
//                 }
//             }
            
//             if (check(temp))
//                 ans.push_back(temp);
//         }
        
//         return ans;
//     }
// };

/*
    n == 3
    we know  : total brackets = 2 * n = 6
    000000 --> 111111
    0 --> (
    1 --> )
    
    ()()()
    010101 
    
    011010
    ())()(
    
    no this is wrong!
    
    -> check function : O(1)
      - If the bracket sequence is correct
      
      for generating the brackets : O(2^N * 16) == O(2 ^ N) 
                           space  : O(2^N) 

    1 << 6 = 1000000 
              111111
*/