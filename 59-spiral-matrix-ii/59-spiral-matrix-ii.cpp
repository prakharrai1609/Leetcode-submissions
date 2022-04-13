class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rfront = 0, rend = n - 1, cfront = 0, cend = n - 1;
        
        int r , c;
        r = 0, c = 0;
        int count = 1;
        vector<vector<int>> ans(n, vector<int> (n));
        
        while (rfront <= rend and cfront <= cend) {
            
            for (int i = cfront; i <= cend; i++) {
                ans[rfront][i] = count++;
            }
            rfront++;
            
            if (rfront > rend)
                break;
            
            for (int i = rfront; i <= rend; i++) {
                ans[i][cend] = count++;
            }
            cend--;
            
            if (cend < cfront)
                break;
            
            for (int i = cend; i >= cfront; i--) {
                ans[rend][i] = count++;
            }
            rend--;
            
            if (rend < rfront)
                break;
            
            for (int i = rend; i >= rfront; i--) {
                ans[i][cfront] = count++;
            }
            cfront++;
                
            if (cfront > cend)
                break;
        }
    
        return ans;
    }
};