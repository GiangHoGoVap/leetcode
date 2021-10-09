int n, m;
vector<string> ans;

class TrieNode
{
public:
    TrieNode *next[26];
    string W;
    TrieNode()
    {
        memset(next, NULL, sizeof(next));
    }
};

TrieNode *buildTrie(vector<string> words)
{
    TrieNode *root = new TrieNode();
    for (string each : words)
    {
        TrieNode *p = root;
        for (char x : each)
        {
            int i = x - 'a';
            if (p->next[i] == NULL)
                p->next[i] = new TrieNode();
            p = p->next[i];
        }
        p->W = each;
    }
    return root;
}

class Solution
{
public:
    void checkFrom(int i, int j, TrieNode *root, vector<vector<char>> &board)
    {
        char c = board[i][j];
        if (board[i][j] == '*' || root->next[c - 'a'] == NULL)
            return;
        board[i][j] = '*';
        root = root->next[c - 'a'];
        if (root->W.length() > 0)
        {
            ans.push_back(root->W);
            root->W = "";
        }
        if (i > 0)
            checkFrom(i - 1, j, root, board);
        if (j > 0)
            checkFrom(i, j - 1, root, board);
        if (i < n - 1)
            checkFrom(i + 1, j, root, board);
        if (j < m - 1)
            checkFrom(i, j + 1, root, board);
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = buildTrie(words);
        n = board.size();
        m = board[0].size();
        ans.clear();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                checkFrom(i, j, root, board);
        return ans;
    }
};

auto static speedup = []
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();