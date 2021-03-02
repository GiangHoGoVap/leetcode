class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i=0; i<command.size(); i++){
            if (command[i] == '(' && command[i+1] == ')'){
                ans += 'o';
                i++;
            }
            if (command[i] == '(' && command[i+1] != ')'){
                i++;
            }
            if (isalpha(command[i])){
                ans += command[i];
            }
        }
        return ans;
    }
};