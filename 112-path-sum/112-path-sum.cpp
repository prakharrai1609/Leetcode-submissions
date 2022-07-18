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
    int sum = 0;
    bool ans = false;
public:
    bool leaf(TreeNode* root) {
        return (!root->left and !root->right);    
    }
    
    void preorder(TreeNode* root, int target) {
        if (!root) return;
        
        if (leaf(root) and sum + root->val == target) {
            ans = true;
            return;
        }
        
        sum += root->val;
        preorder(root->left, target);
        preorder(root->right, target);
        sum -= root->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        preorder(root, targetSum);
        return ans;
    }
};