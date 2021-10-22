class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        map<int,string> m1;
        string res;
        int frequency=0;
        if(s.size()==0) return "";
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            frequency=max(frequency,m[s[i]]);
        }
        map<char,int>::iterator it;
        
        for(it=m.begin();it!=m.end();it++)
        {
            for(int i=0;i<it->second;i++)
            m1[it->second]+=it->first;
        }
        while(frequency)
        {
            if(m1.find(frequency)!=m1.end())
            {
                res+=m1[frequency];
            }
            frequency--;
        }
        return res;
    }
};