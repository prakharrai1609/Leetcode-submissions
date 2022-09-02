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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        double avg = 0, cnt = 0;
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            if (!temp) {
                ans.push_back(avg/cnt);
                avg = 0, cnt = 0;
                if (!q.empty())
                    q.push(nullptr);
            } else {
                avg += temp->val;
                cnt++;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        
        return ans;
    }
};