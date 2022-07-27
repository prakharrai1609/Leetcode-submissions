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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p or root == q or !root) 
            return root;
        TreeNode* p1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* p2 = lowestCommonAncestor(root->right, p, q);
        
        if (p1 and p2) 
            return root;
        else 
            return p1 ? p1 : p2;
    }
    
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
    */
};