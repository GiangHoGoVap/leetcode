class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        for(int i = 0; i<s.size(); i++){
            count[s[i] - 'a'] = i;
        }
        vector<bool> visited(26, 0);
        deque<int> pq;
        for(int i = 0; i<s.size(); i++){
           if(visited[s[i] - 'a']) continue;
           while(!pq.empty() && pq.back() > (s[i]-'a') && i < count[pq.back()]){
               visited[pq.back()] = false;
               pq.pop_back();
           }
            pq.push_back(s[i] - 'a');
            visited[s[i] - 'a'] = true;
        }
        string ans = "";
        while(!pq.empty()){
            ans += pq.front() + 'a';
            pq.pop_front();
        }
        return ans;
    }
};