#define pb emplace_back
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) {
            if (a[0] != b[0]) return a[0] < b[0];  
            return a[1] > b[1];
        });
        
        vector<vector<int>> ans;       
        vector<int> temp = intervals[0];
        
        for (auto v : intervals) {
            if (temp[1] >= v[0]) {
                temp[1] = max(temp[1], v[1]);    
            } else {
                ans.pb(temp);
                temp[0] = v[0];
                temp[1] = v[1];
            }
        }
        ans.pb(temp);
        
        return ans;
    }
};