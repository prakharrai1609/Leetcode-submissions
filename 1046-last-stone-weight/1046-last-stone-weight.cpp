class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int ans = 0;
        multiset<int, greater<int>> m;
        
        for (int stone : stones) {
            m.insert(stone);
        }
        
        multiset<int> :: iterator it1, it2;
        
        while (m.size() > 1) {
            it1 = m.begin();
            it2 = next(m.begin());
            
            if (*it1 - *it2 > 0) 
                m.insert(*it1 - *it2);
            
            m.erase(it1), m.erase(it2);
        }
        
        if (!m.size())
            return 0;
        
        return *(m.begin());
    }
};