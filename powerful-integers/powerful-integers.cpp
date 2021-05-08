class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        vector<int> ans;
        unordered_set<int> mySet;
        int i, j, tmp;
        int tmpX = 1, tmpY = 1;
        if (bound == 0 || bound == 1)
            return ans;
        if ((bound == 2) || (x == 1 && y == 1 && bound > 2))
        {
            ans.push_back(2);
            return ans;
        }

        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                tmp = tmpX + tmpY;
                if (tmp > bound)
                    break;
                if (!mySet.count(tmp))
                {
                    mySet.insert(tmp);
                }
                tmpY *= y;
            }
            tmpX *= x;
            if (tmpX > bound)
                break;
            tmpY = 1;
        }
        ans.assign(mySet.begin(), mySet.end());
        return ans;
    }
};