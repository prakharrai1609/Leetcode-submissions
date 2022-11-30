class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int val : arr) 
            m[val]++;
        unordered_map<int, int> occ;
        for (auto [first, second]: m) {
            if (occ[second])
                return false;
            occ[second] = 1;
        }
        return true;
    }
};