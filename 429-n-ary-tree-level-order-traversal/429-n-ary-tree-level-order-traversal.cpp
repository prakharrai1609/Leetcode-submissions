/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> row;
            int N = q.size();
            for (int i = 0; i < N; i++) {
                Node* t = q.front();
                q.pop();
                for (auto nbr : t->children)
                    q.push(nbr);
                row.push_back(t->val);
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};