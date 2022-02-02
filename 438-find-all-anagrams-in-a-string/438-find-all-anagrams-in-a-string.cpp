class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> res;
        if (p.size() > s.size()) return res; 
        vector<int> pMap(26); 
        vector<int> sMap(26);
    
        int pLastIdx = p.size() - 1;
        for (auto & c : p) pMap[c-'a']++;

        for (int i = 0; i < p.size(); ++i) sMap[s[i]-'a']++;

        if (pMap ==sMap) res.push_back(0); 

        for (int i = 1; i <= size(s) - size(p); ++i) {
		    sMap[s[i - 1] - 'a']--;
		    sMap[s[i + pLastIdx] -  'a']++;
            if (pMap == sMap) res.push_back(i);

	    }
	    return res;
    }
};