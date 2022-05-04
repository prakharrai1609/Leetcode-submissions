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
    TreeNode* maxTree(vector<int> &a, int left, int right) {
        if (left > right) 
            return nullptr;
        
        int ind, mx = INT_MIN;
        
        for (int i = left; i <= right; i++)
            if (mx < a[i]) mx = a[i], ind = i;

        TreeNode* root = new TreeNode(mx);
        root->left = maxTree(a, left, ind - 1);
        root->right = maxTree(a, ind + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return maxTree(nums, 0, nums.size() - 1);
    }
};