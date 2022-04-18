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
private:
    int ans;
public:
    void find(TreeNode * root, int &k) {
        if (!root) return;
        find(root->left, k);
        k -= 1;
        if (!k) {
            ans = root->val;
            return;
        }
        find(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        find(root, k);
        return ans;
    }
};