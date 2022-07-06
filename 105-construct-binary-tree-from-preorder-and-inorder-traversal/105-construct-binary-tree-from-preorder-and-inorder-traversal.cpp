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
    TreeNode* build(vector<int>& pre, vector<int>& in, int& idx, int start, int end) {
        if (start > end) 
            return nullptr;
        
        int pivot, value = pre[idx];
        TreeNode *root = new TreeNode(value);
        
        for (int i = start; i <= end; i++) {
            if (value == in[i]) {
                pivot = i;
                break;
            }
        }
        
        idx++;
        root->left = build(pre, in, idx, start, pivot - 1);
        root->right = build(pre, in, idx, pivot + 1, end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, inorder, idx, 0, size(inorder) - 1);
    }
};