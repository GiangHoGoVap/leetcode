class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        for (int i=0; i<typed.length(); i++){
            if (typed[i] == name[j] && j < name.length()) j++;
            else if (j > 0 && typed[i] == name[j-1]) continue;
            else return false;
        }
        if (j == name.length()) return true;
        return false;
    }
};