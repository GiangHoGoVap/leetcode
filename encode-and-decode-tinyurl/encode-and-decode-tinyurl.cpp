class Solution {
public:
    map<string, string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string random = to_string(rand() % 10000007);
        string t = to_string(time(0));
        string key = random + t;
        m[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));