class Solution {
    stack<pair<char, int>> st;
public:
    void pushT(char val, int k) {
        if (st.empty()) {
            st.push({val, 1});
            return;
        }
        
        pair<char, int> t = st.top();
        if (t.first == val) {
            if (t.second == k - 1) {
                st.pop();
            } else {
                st.pop();
                st.push({val, t.second + 1});
            }
        } else {
            st.push({val, 1});
        }
    }
    
    string removeDuplicates(string s, int k) {
        for (char c : s) {
            pushT(c, k);
        }
        
        string ans = "";
        while (!st.empty()) {
            int cnt = (st.top()).second;
            while (cnt--)
                ans += (st.top()).first;
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};