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
    inline bool ifRange(int val, int low, int high) {
        return (val >= low and val <= high);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> s;
        s.push(root);
        int sum = 0;
        
        while (!s.empty()) {
            TreeNode* t = s.top();
            s.pop();
            
            if (t) 
            {
                if (ifRange(t->val, low, high))
                    sum += t->val;
                s.push(t->left);
                s.push(t->right);
            }
        }
        
        return sum;
    }
};