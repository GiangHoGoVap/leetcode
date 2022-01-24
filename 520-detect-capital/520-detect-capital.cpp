class Solution {
public:
    bool detectCapitalUse(string word) {
        return all_of(word.begin(), word.end(), ::islower)
		or all_of(word.begin(), word.end(), ::isupper)
		or (isupper(word.front()) and all_of(next(word.begin()), word.end(), ::islower));
    }
};