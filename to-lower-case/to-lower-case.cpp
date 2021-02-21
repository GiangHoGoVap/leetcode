class Solution {
public:
    string toLowerCase(string str) {
        int n = str.length();
        char arr[n+1];
        strcpy(arr, str.c_str());
        int i=0;
        char c;
        string ans;
        while (arr[i]){
            c = arr[i];
            ans += tolower(c);
            i++;
        }
        return ans;
    }
};