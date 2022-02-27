// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int ans = INT_MAX;
        vector<int> index(3, -1);
        for (int i = 0; i < S.length(); i++) {
            int c = S[i] - '0';
            index[c] = i;
            int mn = *min_element(index.begin(), index.end());
            int mx = *max_element(index.begin(), index.end());
            
            if (mn != -1) 
                ans = min(ans, mx - mn + 1);
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends