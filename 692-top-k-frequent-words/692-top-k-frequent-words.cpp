class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;
        for (string word : words)
            f[word]++;
        vector<pair<int, string>> vs;
        for (auto p : f) {
            vs.push_back({p.second, p.first});
        }
        
        sort(begin(vs), end(vs), [](pair<int, string> a, pair<int, string> b){
            if (b.first == a.first)
                return b.second > a.second;
            return a.first > b.first;
        });
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(vs[i].second);
        }
        return ans;
    }
};