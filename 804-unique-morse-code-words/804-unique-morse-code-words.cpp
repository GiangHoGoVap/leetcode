class Solution {
private:
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> res;
        for (auto word : words) {
            string code;
            for (auto ch : word) {
                code += morse[ch - 'a'];
            }
            res.insert(code);
        }
        return res.size();
    }
};