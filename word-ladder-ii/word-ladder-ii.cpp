class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        auto expand = [](string &word, unordered_set<string> &dict)
        {
            vector<string> ans;
            for (int i = 0; i < word.size(); i++)
            {
                auto oldChar = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (c == oldChar || !dict.count(word))
                        continue;
                    ans.push_back(word);
                }
                word[i] = oldChar;
            }
            return ans;
        };

        queue<vector<string>> q;
        q.push({beginWord});

        vector<vector<string>> results;
        while (!q.empty() && results.empty())
        {
            unordered_set<string> seen;
            for (int i = q.size() - 1; i >= 0; i--)
            {
                auto path = q.front();
                q.pop();
                auto nextWords = expand(path.back(), dict);
                for (auto &w : nextWords)
                {
                    path.push_back(w);
                    if (w == endWord)
                    {
                        results.push_back(path);
                    }
                    else
                    {
                        q.push(path);
                    }
                    seen.insert(w);
                    path.pop_back();
                }
            }
            for (auto &w : seen)
                dict.erase(w);
        }

        return results;
    }
};