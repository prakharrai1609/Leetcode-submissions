/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
//     multiset<int> s;
//     int ans;
// public:
//     void go(TreeNode* root) {
//         if (!root)
//             return;
//         s.insert(root->val);
//         go(root->left);
//         if (!s.empty() and root->val >= *(--s.end())) {
//             ans++;
//         }
//         go(root->right);
//         s.erase(s.lower_bound(root->val));
//     }
    
//     int goodNodes(TreeNode* root) {
//         ans = 0;
//         go(root);
//         return ans;
//     }
// };

class Solution {
    int ans;
public:
    void go(TreeNode* root, int max_yet) {
        if (!root)
            return;
        int curr_max = max(max_yet, root->val);
        
        go(root->left, curr_max);
        if (root->val >= max_yet) {
            ans++;
        }
        go(root->right, curr_max);
    }
    
    int goodNodes(TreeNode* root) {
        ans = 0;
        go(root, INT_MIN);
        return ans;
    }
};