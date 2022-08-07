/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#define ll long long 
#define vcll vector<ll>
#define vc vector
#define endl '\n'
#define FOR(i, a, b) for (int i = a; i < b; i++)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vc<int> arr(n, 1);
        FOR(i, 1, m) {
            FOR(j, 1, n) {
                arr[j] += arr[j - 1];
            }
        }
        return arr[n - 1];
    }
};

/*
    int uniquePaths(int m, int n) {
        vc<int> pre(n, 1), curr(n, 1);
        FOR(i, 1, m) {
            FOR(j, 1, n) {
                curr[j] = curr[j - 1] + pre[j];
            }
            swap(curr, pre);
        }
        return pre[n - 1];
    }
*/
// @lc code=end

