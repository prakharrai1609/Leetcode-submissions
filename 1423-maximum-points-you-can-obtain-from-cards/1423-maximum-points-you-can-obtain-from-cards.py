class Solution:
    def maxScore(self, a: List[int], k: int) -> int:
        if k == len(a):
            return sum(a)
        
        N = len(a)
        pre = (N + 2) * [0]
        suff = (N + 2) * [0]
        
        pre[1] = a[0]
        for i in range(2, N + 1) :
            pre[i] = pre[i - 1] + a[i - 1]
            
        suff[N] = a[N - 1]
        for i in range(N - 1, 0, -1) :
            suff[i] = suff[i + 1] + a[i - 1]
        
        ans = 0
        for i in range(k + 1) :
            left, right = pre[i], suff[N - (k - i) + 1]
            ans = max(ans, left + right)
            
        return ans