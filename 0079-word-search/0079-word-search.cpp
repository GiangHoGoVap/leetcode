class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {

        if (word.length() > board.size() * board[0].size())
            return false;

        int r = board.size();
        int c = board[0].size();
        for (int row = 0; row < r; row++)
            for (int col = 0; col < c; col++)
                if (board[row][col] == word[0])
                {
                    if (checkWord(board, word, row, col, 0))
                        return true;
                }
        return false;
    }

    bool checkWord(vector<vector<char>> &board, string &word, int row, int col, int pos)
    {
        if (pos == word.length())
            return true;
        if (row >= board.size() || col >= board[0].size())
            return false;
        if (board[row][col] != word[pos])
            return false;

        char temp = board[row][col];
        board[row][col] = ' ';

        if (checkWord(board, word, row + 1, col, pos + 1))
            return true;
        if (checkWord(board, word, row, col + 1, pos + 1))
            return true;
        if (checkWord(board, word, row - 1, col, pos + 1))
            return true;
        if (checkWord(board, word, row, col - 1, pos + 1))
            return true;
        board[row][col] = temp;
        return false;
    }
};