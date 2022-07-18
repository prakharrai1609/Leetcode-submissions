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
    vector<string> ans;
    string path = "";
public:
    bool leaf(TreeNode* root) {
        return (!root->left and !root->right);
    }
    
    void preorder(TreeNode* root) {
        if (!root) return;
        
        string temp = path;
        
        if (leaf(root)) {
            path += to_string(root->val);
            ans.push_back(path);
        } else {
            path += to_string(root->val) + "->";
        }
        
        preorder(root->left);
        preorder(root->right);
        
        path = temp;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        preorder(root);
        return ans;;
    }
};