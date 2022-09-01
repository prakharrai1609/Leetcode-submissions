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
class Solution {
    multiset<int> s;
    int ans;
public:
    void go(TreeNode* root) {
        if (!root)
            return;
        s.insert(root->val);
        go(root->left);
        if (!s.empty() and root->val >= *(--s.end())) {
            ans++;
        }
        go(root->right);
        s.erase(s.lower_bound(root->val));
    }
    
    int goodNodes(TreeNode* root) {
        ans = 0;
        go(root);
        return ans;
    }
};