class Solution
{
public:
    int n;
    vector<vector<int>> arr;

    int getRow(vector<int> &v, int x)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] != x)
                ans++;
            x ^= 1;
        }
        return ans;
    }

    int calc(vector<vector<int>> &v)
    {
        int ans1 = 0, x = 0;
        for (int i = 0; i < n; i++)
            if (v[0][i])
                x++;
        if (n % 2)
        {
            if (x > n / 2)
                x = 1;
            else
                x = 0;
            ans1 = getRow(v[0], x);
        }
        else
            ans1 = min(getRow(v[0], 0), getRow(v[0], 1));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            bool b0 = arr[i] == v[0];
            bool b1 = arr[i] == v[1];
            if (!b0 && !b1)
                return -1;

            if (i % 2 && b0)
                ans++;
            else if (i % 2 == 0 && b1)
                ans++;
        }

        if (ans % 2)
            return -1;
        return ans / 2 + ans1 / 2;
    }

    int chk()
    {
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[0][i])
                c1++;
            else
                c0++;
        }
        if (n % 2 == 0)
        {
            if (c0 != c1)
                return -1;
        }
        else
        {
            if (abs(c0 - c1) != 1)
                return -1;
        }

        vector<vector<int>> v;
        vector<int> temp = arr[0];
        for (int &i : temp)
            i ^= 1;
        v.push_back(arr[0]);
        v.push_back(temp);
        int x = calc(v);
        swap(v[0], v[1]);
        int y = calc(v);

        if (x == -1 && y == -1)
            return -1;
        if (x == -1)
            return y;
        if (y == -1)
            return x;
        return min(x, y);
    }

    int movesToChessboard(vector<vector<int>> &arr)
    {
        n = arr.size();
        this->arr = arr;
        return chk();
    }
};