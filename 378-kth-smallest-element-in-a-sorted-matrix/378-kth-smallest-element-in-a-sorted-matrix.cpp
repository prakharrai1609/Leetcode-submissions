class Solution {
public:
    int kthSmallest(vector<vector<int>>& M, int k) {
        int N = size(M), row = 0, col = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        
        for (int i = 0; i < min(N, k); i++)
            q.push({M[i][0], i, 0});
        
        int ans;
        for (int i = 0; i < k; i++) {
            vector<int> t = q.top();
            q.pop();
            ans = t[0];
            
            int r = t[1], c = t[2];
            if (c + 1 < N)
                q.push({M[r][c + 1], r, c + 1});
        }        
        
        return ans;
    }
};

/*

time : (N * N * log(k))
space : k

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = size(matrix);
        priority_queue<int> pq;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        
        return pq.top();
    }
*/