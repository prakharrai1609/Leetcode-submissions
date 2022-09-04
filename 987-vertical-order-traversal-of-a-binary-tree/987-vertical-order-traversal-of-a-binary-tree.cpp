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
    vector<vector<int>> verticalTraversal(TreeNode* head) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> m;

        q.push({head, {0, 0}});

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();

            TreeNode * curr = temp.first;
            int Vlevel = temp.second.first, Hlevel = temp.second.second;

            m[Hlevel][Vlevel].insert(curr->val);
            if (curr->left) q.push({curr->left, {Vlevel + 1, Hlevel - 1}});
            if (curr->right) q.push({curr->right, {Vlevel + 1, Hlevel + 1}});
        }

        vector<vector<int>> ans;
        for (auto x : m) {
            vector<int> col;
            for (auto y : x.second) {
                for (int v : y.second) col.push_back(v);
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};