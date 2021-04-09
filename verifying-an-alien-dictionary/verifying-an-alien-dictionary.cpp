class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        for(int i = 0; i < order.size(); i++){
            map[order[i]] = i;
        }
        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i], w2 = words[i + 1];
            for(int j = 0; j < max(w1.length(), w2.length()); j++){
                if (j == w1.length()) continue;
                else if (j == w2.length()) return false;
                char parent = w1[j], child = w2[j];
                if (parent != child){
                    if (map[parent] > map[child]) return false;
                    break;
                }
            }
        }
        return true;
    }
};