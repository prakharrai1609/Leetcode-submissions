class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> f;
        vector<pair<int, int>> v;
        for (int i = 0; i < arr.size(); i++)
            f[arr[i]]++;
        for (auto x : f)
            v.push_back({x.second, x.first});
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int cnt = 0, ans = 0, N = arr.size();
        if (N & 1) 
            N += 1;
        N /= 2;
        
        for (auto p : v) {
            if (cnt >= N) break;
            ans++;
            N -= p.first;
        }
        
        return ans;
    }
};