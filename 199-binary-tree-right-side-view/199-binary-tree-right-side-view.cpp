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
public:
    void traverse(TreeNode* root, int& maxLevel, vector<int>& ans, int level) {
        if (!root)
            return;
        
        if (level == maxLevel) {
            ans.push_back(root->val);
            maxLevel++;
        }
        
        traverse(root->right, maxLevel, ans, level + 1);
        traverse(root->left, maxLevel, ans, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        vector<int> ans;
        traverse(root, level, ans, 0);
        return ans;
    }
};