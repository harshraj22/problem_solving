class Solution {
    bool in(map<char, int> &t, map<char, int> &s) {
        for (auto pi: t) {
            if (pi.second > s[pi.first])
                return false;
        }

        return true;
    }

public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return string();
        
        map<char, int> freqt, freq;
        int left = 0, right = 0, n = s.size();
        // pair of: index, length
        pair<int, int> ans = {0, INT_MAX};
        for (auto ch: t) 
            freqt[ch] += 1;

        while (left < n) {
            if (right < n) {
                freq[s[right]] += 1;
                right += 1;
            }
            
            while (in(freqt, freq)) {
                if (ans.second > right-left) 
                    ans = {left, right-left};
                // ans = min(ans, right-left);
                freq[s[left]] -= 1;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left += 1;
            }

            if (right == n && !in(freqt, freq))
                break;
        }

        cout << ans.first << ' ' << ans.second << '\n';
        return (ans.second != INT_MAX? s.substr(ans.first, ans.second): string());
    }
};