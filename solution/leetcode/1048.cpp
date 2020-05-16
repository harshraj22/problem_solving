// https://leetcode.com/problems/longest-string-chain/

class Solution {
    unordered_map<string, int> mp;
    vector<string> input;

    int get(string s) {
        if (mp.find(s) != mp.end())
            return mp[s];
        else if (binary_search(input.begin(), input.end(), s) == 0)
            return INT_MIN;
        else if (s.size() == 1)
            return mp[s] = 1; 
        int ans = 1;   string str;
        for (int i = 0; i < s.size(); i += 1) {
            str = string(s.begin(), s.begin()+i) + string(s.begin()+i+1, s.end());
            ans = max(ans, 1 + get(str));
        }

        return mp[s] = ans;
    }

public:
    int longestStrChain(vector<string>& words) {
        input = words; int ans = 0;
        sort(input.begin(), input.end());
        for (auto word: words) 
            ans = max(ans, get(word));
        return ans;
    }
};
