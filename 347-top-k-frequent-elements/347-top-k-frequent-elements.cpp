class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
            first approach : 
            - create a frequency count
            - push in a priority queue of <count, value> 
            - remove top k - 1 values
            - print the values with same count 
        */
        
        // counting frequency
        unordered_map<int, int> m;
        for (int x : nums) m[x]++;
        
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // keeping most frequent k elemnts only
        for (auto x : m) {
            pq.push({x.second, x.first});
            if (pq.size() > k)
                pq.pop();
        }
        
        vector<int> ans;
        
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        
        return ans;
    }
};