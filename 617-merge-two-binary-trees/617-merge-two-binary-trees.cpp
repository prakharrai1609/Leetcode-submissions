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
    TreeNode* dfs(TreeNode *a, TreeNode *b) {
        int A, B;
        a == nullptr ? A = 0 : A = a->val;
        b == nullptr ? B = 0 : B = b->val;
        
        TreeNode * root = new TreeNode(A + B);
        
        if (a and b) {
            root->left = dfs(a->left, b->left);
            root->right = dfs(a->right, b->right);
        } else if (a and !b) {
            root->left = dfs(a->left, nullptr);
            root->right = dfs(a->right, nullptr);
        } else if (!a and b) {
            root->left = dfs(nullptr, b->left);
            root->right = dfs(nullptr, b->right);
        } else {
            return 0;
        }
        
//         if ((a and a->left) or (b and b->left)) {
//             root->left = dfs(a->left, b->left);
//         } 
        
//         if ((a and a->right) or (b and b->right)) {
//             root->right = dfs(a->right, b->right);
//         }
        
        return root;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode * root;
        if (!root1 and !root2)
            return 0;
        
        root = dfs(root1, root2);
        
        return root;
    }
};