// https://leetcode.com/problems/word-break/

class Solution {
    map<int, bool> cache;
    string input;
    unordered_set<string> dict;

    bool get(int index) {
        if (cache.find(index) != cache.end())   
            return cache[index];
        else if (index >= input.size())
            return true;
        string cur;
        cache[index] = false;
        for (int i = index; i < input.size(); i += 1) {
            cur += input[i];
            if (dict.find(cur) != dict.end()) {
                cache[index] += get(i+1);
            }
        }

        return cache[index];
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        input = s;
        for (auto word: wordDict)
            dict.insert(word);
        return get(0);
    }
};