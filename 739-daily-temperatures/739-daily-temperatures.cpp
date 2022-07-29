class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int N =  size(T);
        vector<int> ans(N, 0);
        stack<pair<int, int> > s;
        
        for (int i = N - 1; i >= 0; i--) {
            while (!s.empty() && s.top().first <= T[i])
                s.pop();
            ans[i] = s.empty() ? 0 : s.top().second - i;
            s.push({T[i], i});
        }
        
        return ans;
    }
};