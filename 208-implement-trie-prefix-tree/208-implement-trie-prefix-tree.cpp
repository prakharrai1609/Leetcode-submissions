class Node {
public:
    char c;
    map<char, Node*> m;
    bool terminal;
    
    Node(char c) {
        this->c = c;
        terminal = false;
    }
};

class Trie {
private:
    Node * root;
    
public:
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node * temp = root;
        for (char c : word) {
            if (!temp->m.count(c)) {
                temp->m[c] = new Node(c);
            }
            temp = temp->m[c];
        }
        temp->terminal = true;
    }
    
    bool search(string word) {
        Node * temp = root;
        for (char c : word) {
            if (temp->m.count(c)){
                temp = temp->m[c];
            } else {
                return false;
            }
        }
        return temp->terminal;
    }
    
    bool startsWith(string prefix) {
        Node * temp = root;
        for (char c : prefix) {
            if (temp->m.count(c))
                temp = temp->m[c];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */