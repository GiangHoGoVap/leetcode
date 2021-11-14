class CombinationIterator
{
public:
    int r;
    vector<string> v;
    int iterator = 0;
    void combination(int index, int i, string data, string temp)
    {

        if (index == r)
        {
            v.push_back(temp);
            return;
        }
        if (i >= data.size())
            return;
        temp[index] = data[i];
        combination(index + 1, i + 1, data, temp);
        combination(index, i + 1, data, temp);
        // return;
    }
    CombinationIterator(string characters, int combinationLength)
    {
        r = combinationLength;
        string temp(r, 'a');
        combination(0, 0, characters, temp);
        //   for(auto i:v)cout<<i<<" ";
    }

    string next()
    {
        if (iterator < v.size())
            return v[iterator++];
        return "";
    }

    bool hasNext()
    {
        if (iterator < v.size())
            return 1;
        return 0;
    }
};
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */