class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int ans = 1;

        for (int i = 0; i < seats.size(); i++)
        {
            if (!seats[i])
            {
                int l = i - 1;
                while (l >= 0 && !seats[l])
                    l--;
                int r = i + 1;
                while (r < seats.size() && !seats[r])
                    r++;

                if (l <= -1)
                    ans = max(ans, r - i);
                else if (r >= seats.size())
                    ans = max(ans, i - l);
                else
                {
                    int m = l + (r - l) / 2;
                    ans = max(ans, min(m - l, r - m));
                }
            }
        }
        return ans;
    }
};