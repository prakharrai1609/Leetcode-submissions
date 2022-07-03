class Node {
public:
	char c;
	map<char, Node*> children;
	bool isTerminal;

	Node(char ch) {
		c = ch;
		isTerminal = false;
	}
};

class Trie {
public:
	Node *root;

	Trie() {
		root = new Node('\0');
	}

	void insert(string word) {
		Node * temp = root;
		for (char ch : word) {
			if (temp->children.count(ch) == 0) {
				temp->children[ch] = new Node(ch);
			}
			temp = temp->children[ch];
		}
		temp->isTerminal = true;
	}

	bool search(string word) {
		Node * temp = root;
		for (char ch : word) {
			if (temp->children[ch]) {
				temp = temp->children[ch];
			} else {
				return false;
			}
		}

		return temp->isTerminal;
	}

	void dfs(Node *temp, string prefix, vector<string>& ans) {
		if (ans.size() == 3)
			return;

		if (temp->isTerminal)
			ans.push_back(prefix);

		for (auto child : temp->children) {
			dfs(temp->children[child.first], prefix + child.first, ans);
		}
	}

	vector<string> sendWord(string prefix) {
		Node * temp = root;
		vector<string> ans;

		for (char c : prefix) {
			if (!temp->children[c])
				return {};
			else
				temp = temp->children[c];
		}

		dfs(temp, prefix, ans);
		return ans;
	}

	void buildTrie(const vector<string>& words) {
		for (string word : words)
			insert(word);
	}
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& words, string word) {
        Trie t;
        t.buildTrie(words);

        vector<vector<string>> ans;
        for (int i = 1; i <= word.size(); i++) {
            ans.push_back(t.sendWord(word.substr(0, i)));
        }

        return ans;
    }
};