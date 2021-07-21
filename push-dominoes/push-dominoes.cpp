class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int i = 0, j = 0, n = dominoes.size();
        while (i < n)
        {
            if (dominoes[i] == 'L')
                while (j < i)
                    dominoes[j++] = 'L';
            else if (dominoes[i] == 'R')
            {
                int k = i;
                while (++i != n && dominoes[i] != 'L')
                    if (dominoes[i] == 'R')
                        k = i;
                    else
                        dominoes[i] = 'R';
                k = i - k - 1;
                if (i == n)
                    break;
                bool flag = (k % 2 != 0);
                k = k >> 1;
                int w = i - 1;
                while (k--)
                    dominoes[w--] = 'L';
                if (flag)
                    dominoes[w] = '.';
                j = i + 1;
            }
            i++;
        }
        return dominoes;
    }
};