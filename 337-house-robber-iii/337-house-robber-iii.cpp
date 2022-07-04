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
private:
    map<TreeNode*, int> cost;
    
public:
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        
        if (cost[root])
            return cost[root];
        
        // if we don't pick the root node
        int op1 = rob(root->left) + rob(root->right);
        
        // if we pick the root node
        int op2 = root->val;
        
        if (root->left) {
            op2 += rob(root->left->left) + rob(root->left->right);
        }
        
        if (root->right) {
            op2 += rob(root->right->left) + rob(root->right->right);
        }
        
        return cost[root] = max(op1, op2);
    }
};