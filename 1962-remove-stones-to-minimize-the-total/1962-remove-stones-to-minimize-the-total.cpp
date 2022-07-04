class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int stones : piles) {
            pq.push(stones);
        }
        
        while (k--) {
            int temp = pq.top();
            pq.pop();
            
            temp = ceil((temp * 1.0) / 2);
            pq.push(temp);
        }
        
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};