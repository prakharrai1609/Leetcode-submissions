class Solution {
    stack<TreeNode*> s;
public:
    
    /* recursive solution
    
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
    
    */
    
    TreeNode* invertTree(TreeNode* root) {
        s.push(root);
        while (!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            
            if (t) {
                s.push(t->left);
                s.push(t->right);
                swap(t->left, t->right);
            }
        }
        
        return root;
    }
};