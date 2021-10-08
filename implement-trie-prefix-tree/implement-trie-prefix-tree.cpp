class TrieNode {
    public:
        bool terminal = false;
        TrieNode * elements[26];
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
                elements[i] = nullptr;

            terminal = false;
        }
};

class Trie {
    TrieNode * root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * node = root;
        for (char current : word)
        {
            int index = current - 'a';
            if (node->elements[index] == NULL)
            {
                node->elements[index] = new TrieNode();
            }
            node = node->elements[index];
        }
        node->terminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return (searchHelper (word) == 1? true : false);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return(searchHelper (prefix) >= 0 ? true : false);
    }
    
    int searchHelper(string word)
    {
       TrieNode * node = root;
       int i = 0;
       for (char current : word)
       {
            int index = current - 'a';
            if (node->elements[index] != NULL)
            {
                node = node->elements[index];
            }
            else
                return -1;
       }
        // For search(), check if this node is terminal
        if (node->terminal == true)
            return 1;
        
        return 0;       
    }
};

static int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */