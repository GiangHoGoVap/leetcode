const int N = 1e5 + 3;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
class Solution
{
public:
    int parent[(int)2e4 + 1], ind[(int)2e4 + 1];
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v)
    {
        parent[v] = v;
        ind[v] = rand();
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (ind[a] < ind[b])
                swap(a, b);
            parent[b] = a;
        }
    }
    vvi prime_vector_sieve(int N)
    {
        vvi prime(N);
        for (int i = 2; i < N; ++i)
            if (prime[i].empty())
                for (int j = i; j < N; j += i)
                {
                    prime[j].push_back(i);
                }
        return prime;
    }
    int normal(vector<int> &A)
    {
        int z = *max_element(A.begin(), A.end());
        vvi v = prime_vector_sieve(z + 2);
        int n = A.size();
        vi s[z + 2];
        for (int i = 0; i < A.size(); i++)
        {
            for (auto j : v[A[i]])
            {
                s[j].push_back(i);
            }
        }
        for (int i = 0; i < (int)n; i++)
            make_set(i);
        for (int i = 1; i < z + 2; i++)
        {
            if (s[i].empty() == 0)
                for (auto j : s[i])
                {
                    union_sets(j, s[i][0]);
                }
        }
        vector<int> fin(z + 2, 0);
        for (int i = 0; i < n; i++)
        {
            fin[find_set(i)]++;
        }
        return *max_element(fin.begin(), fin.end());
    }
    int largestComponentSize(vector<int> &A)
    {
        int z = *max_element(A.begin(), A.end());
        for (int i = 0; i < (int)A.size(); i++)
            parent[i] = ind[i] = 0;
        if (z < 1e4)
            return normal(A);
        int n = A.size();
        vi s[z + 2];
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 2; j <= sqrt(A[i]); j++)
            {
                if ((A[i] % j) == 0)
                {
                    s[j].push_back(i);
                    s[(A[i] / j)].push_back(i);
                }
            }
            if (A[i] != 1)
                s[A[i]].push_back(i);
        }
        for (int i = 0; i < (int)n; i++)
            make_set(i);
        for (int i = 1; i < z + 2; i++)
        {
            if (s[i].empty() == 0)
                for (auto j : s[i])
                {
                    union_sets(j, s[i][0]);
                }
        }
        vector<int> fin(z + 2, 0);
        for (int i = 0; i < n; i++)
        {
            fin[find_set(i)]++;
        }
        return *max_element(fin.begin(), fin.end());
    }
};