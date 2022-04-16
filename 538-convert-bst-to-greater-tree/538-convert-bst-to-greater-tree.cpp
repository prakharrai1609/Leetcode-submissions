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
    int add = 0;
public:
    void update(TreeNode* root) {
        if (!root) return;
        if (root->right) update(root->right);
        
        add += root->val;
        root->val = add;
        
        if (root->left) update(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        update(root);
        return root;
    }
};