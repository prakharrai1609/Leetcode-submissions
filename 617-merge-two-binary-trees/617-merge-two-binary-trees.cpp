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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 and root2) {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
        } else {
            return root1 ? root1 : root2;
        }
    
        return root1;
    }
    
    /*
     * why this works?
     * because when we go into the else condition, if a particular node 
       doesn't exist in one tree and exists in another, returning the existing node
       will return the whole branch of that node i.e. if a node pointer is 
       returned the whole branch with all the nodes in that branch are returned and connected to
       the tree.
    */
};

/*
Over work!!!

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

*/