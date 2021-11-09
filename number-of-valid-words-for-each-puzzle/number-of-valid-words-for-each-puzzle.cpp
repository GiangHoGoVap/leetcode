class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        int P = puzzles.size();
        int W = words.size();

        vector<int> letterMask(26, 0);

        for (int i = 0, mask = 1; i < 26; ++i, mask <<= 1)
        {
            letterMask[i] = mask;
        }

        unordered_map<int, int> wordsMask;

        for (int i = 0; i < W; ++i)
        {
            int mask = 0;

            for (char c : words[i])
            {
                mask = mask | letterMask[c - 'a'];
            }

            ++wordsMask[mask];
        }

        vector<int> result(P, 0);

        for (int i = 0; i < P; ++i)
        {
            int mask = 0;

            for (char c : puzzles[i])
            {
                mask = mask | letterMask[c - 'a'];
            }

            int subMask = mask;

            while (subMask)
            {
                if ((subMask & letterMask[puzzles[i][0] - 'a']) && wordsMask.count(subMask))
                {
                    result[i] += wordsMask[subMask];
                }
                subMask = (subMask - 1) & mask;
            }
        }

        return result;
    }
};