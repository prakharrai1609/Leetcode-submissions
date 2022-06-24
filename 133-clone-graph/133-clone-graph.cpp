/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    map<Node*, Node*> add;
    
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        
        if (!add[node]) {
            add[node] = new Node(node->val);
            for (auto nbr : node->neighbors) {
                add[node]->neighbors.push_back(cloneGraph(nbr));
            }
        }
        
        return add[node];
    }
};