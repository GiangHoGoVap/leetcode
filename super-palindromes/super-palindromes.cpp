class Solution {
public:
    bool check(long long n) {
        long long num = n, rev = 0, digit;
        do {
            digit = num % 10;
            rev = (rev * 10) + digit;
            num = num / 10;
        } while (num != 0);
        
        return rev == n;
    }
    
    long long nextPalindrome(long long palindrome, long long num) { // if num = 123 this function will return 123321
        while (num > 0) {
            palindrome = palindrome * 10 + (num % 10);
            num /= 10;
        }
        return palindrome;
    }

    vector<long long> generatePalindromes(long long left, long long right) {
        vector<long long> res; 
        long long number;
        for (int i = 1; (number = nextPalindrome(i, i / 10)) <= right; i++) {
            if (number >= left && number <= right) res.push_back(number);
            number = nextPalindrome(i, i);
            if (number >= left && number <= right) res.push_back(number);
        }
        return res;
    }
    
    int superpalindromesInRange(string left, string right) {
        long long r = stoull(right), l = stoull(left);
        int cnt = 0;
        for (auto &ul : generatePalindromes(sqrt(l), sqrt(r))) {
            if (check(ul * ul)) cnt++;
        }
        return cnt;
    }
};