class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) 
        {
            invertTree(root->left);
            invertTree(root->right);
            
            // we are directly swapping the pointers
            swap(root->left, root->right);
        }
        
        return root;
    }
};