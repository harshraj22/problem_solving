// https://leetcode.com/problems/word-ladder/

// Used BFS, Why DFS doesn't work ? read here: https://leetcode.com/problems/word-ladder/discuss/623240/Help-me-with-my-code

class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wordList) {
        #define pi pair<string, int>
        queue<pi> q; q.push({b, 1});
        unordered_set<string> vis = {b}, words = {wordList.begin(), wordList.end()};
        
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            string s = cur.first;
            if (s == e) return cur.second;
            for (int i = 0; i < s.size(); i += 1) {
                for (char ch = 'a'; ch <= 'z'; ch += 1) {
                    s[i] = ch;
                    if (vis.find(s) == vis.end() && words.find(s) != words.end()) {
                        q.push({s, cur.second + 1});
                        vis.insert(s);
                    }
                    s[i] = cur.first[i];
                }
            }
        }
        return 0;        
    }
};