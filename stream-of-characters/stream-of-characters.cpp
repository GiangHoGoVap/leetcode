class StreamChecker {
public:
    vector<unordered_map<char, int>> trie;
    vector<bool> term;
    vector<int> fail;
    int curPos;

    StreamChecker(vector<string>& words) {
	    // Build the Trie
        int total = 0;
        unordered_map<char, int> root;
        this->trie.push_back(root);
        this->term.push_back(false);
        this->fail.push_back(0);
        for (string word : words) {
            int cur = 0;
            for (char c : word) {
                if (this->trie[cur].find(c) != this->trie[cur].end()) {
                    cur = this->trie[cur][c];
                } else {
                    unordered_map<char, int> newNode;
                    this->trie.push_back(newNode);
                    this->term.push_back(false);
                    total++;
                    this->trie[cur][c] = total;
                    cur = total;
                }
            }
            this->term[cur] = true;
        }

        // Maintain fail pointer, so each time when an attempting further match fail,
		// jump to the position where the longest suffix of current path is a prefix in the Trie.
        for (int i = 0; i < this->trie.size(); i++) {
            this->fail.push_back(0);
        }
		// Need follow BFS order to create failing pointers so that upper level nodes
		// should  have their correct failing jumping positions when processing a lower node in Trie.
        queue<pair<int, unordered_map<char, int>>> nodes;
        for (auto kv: this->trie[0]) {
            auto o = make_pair(kv.second, this->trie[kv.second]);
            nodes.push(o);   
        }
        while (!nodes.empty()) {
            auto p = nodes.front();
            nodes.pop();
            auto i = p.first;
            auto node = p.second;
            for (auto kv : node) {
                auto pp = make_pair(kv.second, this->trie[kv.second]);
                nodes.push(pp);
            }
            for (auto kv : node) {
                char child = kv.first;
                int pos = kv.second;
                int f = this->fail[i];
				// Very similar with KMP algorithm to find the failing position, but here the jumping can
				// be anywhere on the Trie.
                while (f != 0 && this->trie[f].find(child) == trie[f].end()) {
                    f = this->fail[f];
                }
                if (this->trie[f].find(child) != trie[f].end()) {
                    f = this->trie[f][child];
                }
                this->fail[pos] = f;
				// Here we inherit the termination flag from failing position, so that if any node in the failing
				// chain is a valid word, the current position will yield a true answer.
                if (this->term[this->fail[pos]]) {
                    this->term[pos] = true;
                }
            }
        }
        this->curPos = 0;
    }

    
    bool query(char letter) {
	    // Find the matching position on Trie.
        while (this->curPos > 0 && this->trie[this->curPos].find(letter) == this->trie[this->curPos].end()) {
            this->curPos = this->fail[this->curPos];
        }
        if (this->trie[this->curPos].find(letter) != this->trie[this->curPos].end()) {
            this->curPos = this->trie[this->curPos][letter];
        }
		
        return this->term[this->curPos];
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */