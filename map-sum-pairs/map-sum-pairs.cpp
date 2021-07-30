class MapSum
{
public:
    /** Initialize your data structure here. */
    unordered_map<char, MapSum *> m;
    int val;
    MapSum()
    {
        m.clear();
        val = 0;
    }

    void insert(string key, int val)
    {
        MapSum *root = this;
        int i = 0;

        while (i < key.size())
        {
            if (root->m.find(key[i]) == root->m.end())
                root->m[key[i]] = new MapSum;
            root = root->m[key[i]];
            i++;
        }
        root->val = val;
    }

    int getTotal(MapSum *root)
    {
        if (!root)
            return 0;
        int ans = root->val;

        for (auto i : root->m)
        {
            ans += getTotal(i.second);
        }
        return ans;
    }

    int sum(string prefix)
    {
        MapSum *root = this;
        int i = 0;

        while (i < prefix.size() && root != NULL)
        {
            if (root->m.find(prefix[i]) == root->m.end())
                return 0;
            root = root->m[prefix[i]];
            i++;
        }
        return getTotal(root);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */