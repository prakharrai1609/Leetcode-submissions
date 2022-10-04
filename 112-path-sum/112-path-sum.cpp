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
    bool path_sum(TreeNode* root, int target) {
        if (!root)
            return false;
        
        if (!root->left and !root->right)
            return target == root->val;
        
        bool op1 = path_sum(root->left, target - root->val);
        bool op2 = path_sum(root->right, target - root->val);

        return (op1 or op2);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return path_sum(root, targetSum);
    }
};