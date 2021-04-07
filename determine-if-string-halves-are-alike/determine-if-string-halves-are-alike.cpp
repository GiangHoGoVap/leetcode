class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowel = "aeiouAEIOU";
        int vowels1 = 0, vowels2 = 0, n = s.size();
        for (int i=0; i<n/2; i++) {
            if (vowel.find(s[i]) != string::npos) vowels1++;
            if (vowel.find(s[n-i-1]) != string::npos) vowels2++;
        }
        return vowels1 == vowels2;
    }
};