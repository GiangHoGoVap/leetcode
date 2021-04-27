class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime;

        for (int i = 0; i < n; i++)
        {
            prime.push_back(false);
        }

        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i] == false)
            {
                for (int j = i * i; j <= n; j += i)
                    prime[j] = true;
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i] == false)
                count++;
        }
        return count;
    }
};
