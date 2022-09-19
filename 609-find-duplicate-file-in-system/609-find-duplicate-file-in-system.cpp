class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        
        for (string path: paths) {
            string pt;
            int i;
            for (i = 0; i <  path.size() && path[i] != ' '; i++) pt += path[i];
            pt += '/';
            i++;
            
            while (i < path.size()) {
                string temp, file;
                
                while (i < path.size() && path[i] != '(') 
                    temp += path[i++];
                
                while (i < path.size() && path[i] != ' ') 
                    file += path[i++];
                
                m[file].push_back(pt + temp);
                ++i;
            }
        }
        
        for (auto &x: m) {
            if (x.second.size() > 1) 
                ans.push_back(x.second);
        }
        return ans;
    }
};