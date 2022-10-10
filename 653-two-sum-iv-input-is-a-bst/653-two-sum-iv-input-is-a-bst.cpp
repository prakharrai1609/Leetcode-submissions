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
    vector<int> a;
public:
    void in(TreeNode* root) {
        if (!root)
            return;
        in(root->left);
        a.push_back(root->val);
        in(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        in(root);
        unordered_map<int, bool> m;
        for (int num : a) {
            if (m[k - num]) return true;
            m[num] = 1;
        }
        return false;
    }
};