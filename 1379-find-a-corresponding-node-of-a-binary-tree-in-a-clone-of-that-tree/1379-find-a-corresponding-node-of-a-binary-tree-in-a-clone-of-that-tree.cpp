/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans;
public:
    void travel(TreeNode* og, TreeNode* cl, TreeNode* target) {
        if (!og) return;
        
        if (og == target) {
            ans = cl;
            return;
        }
        
        travel(og->left, cl->left, target);
        travel(og->right, cl->right, target);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *og, *cl;
        og = original, cl = cloned;
        travel(og, cl, target);
        return ans;
    }
};