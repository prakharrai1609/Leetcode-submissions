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
    bool check(TreeNode* r, TreeNode* t) {
        if (!r and !t) return true;
        if (!r or !t) return false;
        
        if (r->val == t->val) {
            bool op1 = check(r->left, t->left);
            bool op2 = check(r->right, t->right);
            
            return op1 and op2;
        } else {
            return false;
        }
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode *t = s.top();
            s.pop();
            
            if (t) {
                if (t->val == subRoot->val) {
                    TreeNode* st = subRoot;
                    bool ans = check(t, st);
                    if (ans)
                        return true;
                }
                s.push(t->left);
                s.push(t->right);
            }
        }
        
        return false;
    }
};