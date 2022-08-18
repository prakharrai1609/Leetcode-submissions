class Solution {
public:
    void attach(TreeNode* root, TreeNode* temp) {
        TreeNode* t = root;
        while (t->right)
            t = t->right;
        t->right = temp;
    }
    
    void fix(TreeNode* root) {
        if (!root) return;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        attach(root, temp);
    }
    
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        fix(root);
        flatten(root->right);
    }
};