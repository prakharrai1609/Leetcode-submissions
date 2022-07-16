class Solution {
    int ans = 0;
public:
    int f(TreeNode* root) {
        if (!root)
            return 0;
        
        int hleft = f(root->left);
        int hright = f(root->right);
        
        // ans is the diameter we are updating here
        ans = max(ans, hleft + hright);
        
        // we are returning the max of the max height to update the diameter 
        // from the calling node  
        return max(hleft, hright) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return ans;
    }
};

/*

    Unoptimal solution
    ==================
    
class Solution {
public:
    int height(TreeNode* root) {
        if (!root) 
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) 
            return 0;
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = height(root->left) + height(root->right);
        
        return max({op1, op2, op3});
    }
};

*/